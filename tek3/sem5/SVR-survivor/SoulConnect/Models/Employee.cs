using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Employee
    {
        [Key]
        public int Id { get; set; }

        [JsonProperty("email")]
        public string? Email { get; set; }

        [JsonProperty("name")]
        public string? Name { get; set; }

        [JsonProperty("surname")]
        public string? Surname { get; set; }
        
        [JsonProperty("birth_date")]
        public DateTime? BirthDate { get; set; }

        [JsonProperty("gender")]
        public string? Gender { get; set; }

        [JsonProperty("work")]
        public string? Work { get; set; }

        public string? ImagePath { get; set; }
    }
}