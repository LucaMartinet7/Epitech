using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;

namespace SoulConnect.Services
{
    public class EncountersService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;

        public EncountersService(HttpClient httpClient, IOptions<ApiSettings> apiSettings)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
            _httpClient.BaseAddress = new Uri(_apiSettings.BaseUrl);
        }

        public async Task<List<Encounter>> GetEncountersAsync()
        {
            Console.WriteLine("Starting to fetch encounters list...");

            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                Console.WriteLine("Sending request to /api/encounters...");
                var response = await _httpClient.GetAsync("encounters");
                response.EnsureSuccessStatusCode();
                Console.WriteLine("Successfully received response from /api/encounters.");

                var content = await response.Content.ReadAsStringAsync();
                var encounters = JsonConvert.DeserializeObject<List<Encounter>>(content);
                Console.WriteLine($"Fetched {encounters.Count} encounters.");

                foreach (var encounter in encounters)
                {
                    Console.WriteLine($"Fetching details for encounter ID: {encounter.Id}...");
                    var detailedEncounter = await GetEncounterDetailsAsync(encounter.Id);
                    if (detailedEncounter != null)
                    {
                        encounter.Comment = detailedEncounter.Comment;
                        encounter.Source = detailedEncounter.Source;
                        Console.WriteLine($"Encounter ID: {encounter.Id} updated with Comment and Source.");
                    }
                }

                Console.WriteLine("Completed fetching and updating encounters list.");
                return encounters;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching encounters: {ex.Message}");
                return new List<Encounter>();
            }
        }

        private async Task<Encounter?> GetEncounterDetailsAsync(int encounterId)
        {
            Console.WriteLine($"Starting to fetch details for encounter ID: {encounterId}...");

            try
            {
                var response = await _httpClient.GetAsync($"encounters/{encounterId}");
                response.EnsureSuccessStatusCode();
                Console.WriteLine($"Successfully received details for encounter ID: {encounterId}.");

                var content = await response.Content.ReadAsStringAsync();
                var encounter = JsonConvert.DeserializeObject<Encounter>(content);

                return encounter;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching details for encounter ID {encounterId}: {ex.Message}");
                return null;
            }
        }

        public async Task<List<Encounter>> GetEncountersByCustomerAsync(int customerId)
        {
            Console.WriteLine($"Fetching encounters for customer ID: {customerId}...");
            var encounters = await GetEncountersAsync();
            var customerEncounters = encounters.FindAll(e => e.CustomerId == customerId);
            Console.WriteLine($"Found {customerEncounters.Count} encounters for customer ID: {customerId}.");

            return customerEncounters;
        }
    }
}
