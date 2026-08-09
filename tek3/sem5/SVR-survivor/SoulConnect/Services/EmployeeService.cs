using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;
using System.Net.Http.Headers;
using System.IO;
using Microsoft.AspNetCore.Hosting;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Linq;

namespace SoulConnect.Services
{
    public class EmployeeService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;
        private readonly string _imagesDirectory;

        public EmployeeService(HttpClient httpClient, IOptions<ApiSettings> apiSettings, IWebHostEnvironment environment)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;

            _imagesDirectory = Path.Combine(environment.WebRootPath, "images", "employees");
            _httpClient.BaseAddress = new Uri(_apiSettings.BaseUrl);
        }

        private async Task<string> DownloadEmployeeImageAsync(int employeeId)
        {
            try
            {
                var response = await _httpClient.GetAsync($"employees/{employeeId}/image");
                response.EnsureSuccessStatusCode();

                var imageBytes = await response.Content.ReadAsByteArrayAsync();

                if (!Directory.Exists(_imagesDirectory))
                {
                    Directory.CreateDirectory(_imagesDirectory);
                }

                var imagePath = Path.Combine(_imagesDirectory, $"{employeeId}.jpg");
                await File.WriteAllBytesAsync(imagePath, imageBytes);

                return imagePath;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error downloading image for employee {employeeId}: " + ex.Message);
                return null;
            }
        }

        private async Task<Employee> GetEmployeeDetailsAsync(int employeeId)
        {
            try
            {
                var response = await _httpClient.GetAsync($"employees/{employeeId}");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var employeeDetails = JsonConvert.DeserializeObject<Employee>(content);

                return employeeDetails;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching details for employee {employeeId}: " + ex.Message);
                return null;
            }
        }

        public async Task<List<Employee>> GetEmployeesAsync()
        {
            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync("employees");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var employees = JsonConvert.DeserializeObject<List<Employee>>(content);

                if (employees == null || !employees.Any())
                {
                    Console.WriteLine("No employees found.");
                    return new List<Employee>();
                }

                foreach (var employee in employees)
                {
                    var details = await GetEmployeeDetailsAsync(employee.Id);
                    if (details != null)
                    {
                        employee.BirthDate = details.BirthDate;
                        employee.Gender = details.Gender;
                        employee.Work = details.Work;
                    }

                    var imagePath = await DownloadEmployeeImageAsync(employee.Id);
                    if (imagePath != null)
                    {
                        employee.ImagePath = imagePath;
                    }
                }

                return employees;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching employees: " + ex.Message);
                return new List<Employee>();
            }
        }
    }
}
