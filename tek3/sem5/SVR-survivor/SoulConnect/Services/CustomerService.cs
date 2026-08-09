using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;

namespace SoulConnect.Services
{
    public class CustomerService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;
        private readonly string _imagesDirectory;

        public CustomerService(HttpClient httpClient, IOptions<ApiSettings> apiSettings, IWebHostEnvironment environment)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
            _imagesDirectory = Path.Combine(environment.WebRootPath, "images", "customers");
        }

        private void SetDefaultRequestHeaders()
        {
            _httpClient.DefaultRequestHeaders.Clear();
            _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
            _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
            _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);
        }

        private async Task<string> DownloadCustomerImageAsync(int customerId)
        {
            try
            {
                SetDefaultRequestHeaders();
                var response = await _httpClient.GetAsync($"customers/{customerId}/image");
                response.EnsureSuccessStatusCode();

                var imageBytes = await response.Content.ReadAsByteArrayAsync();

                if (!Directory.Exists(_imagesDirectory))
                {
                    Directory.CreateDirectory(_imagesDirectory);
                }

                var imagePath = Path.Combine(_imagesDirectory, $"{customerId}.jpg");
                await File.WriteAllBytesAsync(imagePath, imageBytes);

                return imagePath;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error downloading image for customer {customerId}: " + ex.Message);
                return null;
            }
        }

        public async Task<Customer> GetCustomerDetailsAsync(int customerId)
        {
            try
            {
                SetDefaultRequestHeaders();
                var response = await _httpClient.GetAsync($"customers/{customerId}");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var customer = JsonConvert.DeserializeObject<Customer>(content);

                var imagePath = await DownloadCustomerImageAsync(customerId);
                if (imagePath != null)
                {
                    customer.ImagePath = imagePath;
                }

                return customer;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching customer details: " + ex.Message);
                return null;
            }
        }

        public async Task<List<Customer>> GetCustomersAsync()
        {
            try
            {
                SetDefaultRequestHeaders();
                var response = await _httpClient.GetAsync("customers");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var partialCustomers = JsonConvert.DeserializeObject<List<Customer>>(content);

                var customers = new List<Customer>();
                foreach (var customer in partialCustomers)
                {
                    var fullCustomer = await GetCustomerDetailsAsync(customer.Id);
                    if (fullCustomer != null)
                    {
                        customers.Add(fullCustomer);
                    }
                }

                return customers;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching customers: " + ex.Message);
                return new List<Customer>();
            }
        }
    }

}
