using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Events
    {
        [Key]
        public int Id { get; set; }
        [JsonProperty("name")]
        public string? Name { get; set; }
        [JsonProperty("date")]
        public DateTime? Date { get; set; }
        [JsonProperty("duration")]
        public int? Duration { get; set; }
        [JsonProperty("max_participants")]
        public int? MaxParticipants { get; set; }
        [JsonProperty("location_x")]
        public string? LocationX { get; set; }
        [JsonProperty("location_y")]
        public string? LocationY { get; set; }
        [JsonProperty("type")]
        public string? Type { get; set; }
        [JsonProperty("employee_id")]
        public int? EmployeeId { get; set; }
        [JsonProperty("location_name")]
        public string? LocationName { get; set; }
        
        public Employee? Employee { get; set; }
    }
}
