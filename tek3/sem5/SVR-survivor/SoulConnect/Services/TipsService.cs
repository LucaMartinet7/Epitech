using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;
using System.Net.Http.Headers;

namespace SoulConnect.Services
{
    public class TipsService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;

        public TipsService(HttpClient httpClient, IOptions<ApiSettings> apiSettings)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
        }

        public async Task<List<Tip>> GetTipsAsync()
        {
            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync("tips");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                return JsonConvert.DeserializeObject<List<Tip>>(content);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching tips: " + ex.Message);
                return new List<Tip>();
            }
        }
    }
}
