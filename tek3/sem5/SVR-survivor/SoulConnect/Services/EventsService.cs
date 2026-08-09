using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;
using System.Net.Http.Headers;

namespace SoulConnect.Services
{
    public class EventsService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;

        public EventsService(HttpClient httpClient, IOptions<ApiSettings> apiSettings)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
        }

        public async Task<Events> GetEventAsync(int eventId)
        {
            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync($"events/{eventId}");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                return JsonConvert.DeserializeObject<Events>(content);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching event: " + ex.Message);
                return null;
            }
        }

        public async Task<List<Events>> GetEventsAsync()
        {
            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                var response = await _httpClient.GetAsync("events");
                response.EnsureSuccessStatusCode();

                var content = await response.Content.ReadAsStringAsync();
                var eventsList = JsonConvert.DeserializeObject<List<Events>>(content);

                if (eventsList == null || !eventsList.Any())
                {
                    Console.WriteLine("No events found.");
                    return new List<Events>();
                }

                foreach (var ev in eventsList)
                {
                    var detailedEvent = await GetEventAsync(ev.Id);
                    if (detailedEvent != null)
                    {
                        ev.LocationX = detailedEvent.LocationX;
                        ev.LocationY = detailedEvent.LocationY;
                        ev.Type = detailedEvent.Type;
                        ev.EmployeeId = detailedEvent.EmployeeId;
                        ev.LocationName = detailedEvent.LocationName;
                    }
                }

                return eventsList;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error fetching events: " + ex.Message);
                return new List<Events>();
            }
        }
    }
}
