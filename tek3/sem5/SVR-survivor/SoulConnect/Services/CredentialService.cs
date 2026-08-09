using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;

namespace SoulConnect.Services
{
    public class CredentialService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;

        public CredentialService(HttpClient httpClient, IOptions<ApiSettings> apiSettings)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
        }

        public async Task<List<Credentials>> GetCredentialsAsync()
        {
            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync("credentials");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                return JsonConvert.DeserializeObject<List<Credentials>>(content);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching credentials: " + ex.Message);
                return new List<Credentials>();
            }
        }
    }
}
