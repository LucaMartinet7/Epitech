using Newtonsoft.Json;
using System.ComponentModel.DataAnnotations;

namespace SoulConnect.Models
{
    public class Customer
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
        public DateTime BirthDate { get; set; }

        [JsonProperty("gender")]
        public string? Gender { get; set; }

        [JsonProperty("description")]
        public string? Description { get; set; }

        [JsonProperty("astrological_sign")]
        public string? AstrologicalSign { get; set; }

        [JsonProperty("phone_number")]
        public string? PhoneNumber { get; set; }

        [JsonProperty("address")]
        public string? Address { get; set; }

        public string? ImagePath { get; set; }
    }
}