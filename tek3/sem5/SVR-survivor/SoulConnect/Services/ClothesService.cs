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
    public class ClothesService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;
        private readonly string _imagesDirectory;

        public ClothesService(HttpClient httpClient, IOptions<ApiSettings> apiSettings, IWebHostEnvironment environment)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;

            _imagesDirectory = Path.Combine(environment.WebRootPath, "images", "clothes");
            _httpClient.BaseAddress = new Uri(_apiSettings.BaseUrl);
        }

        private async Task<string> DownloadClotheImageAsync(int clotheId)
        {
            try
            {
                var imageFileName = $"{clotheId}.jpg";
                var imagePath = Path.Combine(_imagesDirectory, imageFileName);

                Console.WriteLine($"[INFO] Checking if image for clothe {clotheId} already exists at {imagePath}.");

                if (File.Exists(imagePath))
                {
                    Console.WriteLine($"[INFO] Image for clothe {clotheId} already exists. Skipping download.");
                    return $"/images/clothes/{imageFileName}";
                }

                Console.WriteLine($"[INFO] Image for clothe {clotheId} does not exist. Downloading from API.");

                var response = await _httpClient.GetAsync($"clothes/{clotheId}/image");
                response.EnsureSuccessStatusCode();

                var imageBytes = await response.Content.ReadAsByteArrayAsync();

                if (!Directory.Exists(_imagesDirectory))
                {
                    Console.WriteLine($"[INFO] Directory {_imagesDirectory} does not exist. Creating directory.");
                    Directory.CreateDirectory(_imagesDirectory);
                }

                await File.WriteAllBytesAsync(imagePath, imageBytes);

                Console.WriteLine($"[INFO] Image for clothe {clotheId} downloaded successfully and saved at {imagePath}.");

                return $"/images/clothes/{imageFileName}";
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[ERROR] Error downloading image for clothe {clotheId}: {ex.Message}");
                return null;
            }
        }

        public async Task<List<Clothe>> GetCustomerClothesAsync(int customerId)
        {
            try
            {
                Console.WriteLine($"[INFO] Fetching clothes for customer {customerId}.");

                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync($"customers/{customerId}/clothes");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var clothes = JsonConvert.DeserializeObject<List<Clothe>>(content);

                Console.WriteLine($"[INFO] Retrieved {clothes.Count} clothes for customer {customerId}. Downloading images.");

                foreach (var clothe in clothes)
                {
                    var imagePath = await DownloadClotheImageAsync(clothe.Id);
                    if (imagePath != null)
                    {
                        clothe.ImagePath = imagePath;
                    }
                }

                Console.WriteLine($"[INFO] Finished processing clothes for customer {customerId}.");
                return clothes;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[ERROR] Error fetching clothes for customer {customerId}: {ex.Message}");
                return new List<Clothe>();
            }
        }
    }
}
