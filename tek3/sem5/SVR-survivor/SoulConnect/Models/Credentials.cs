using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Credentials
    {
        [Key]
        [JsonProperty("email")]
        public string Email { get; set; } = string.Empty;

        [Required]
        [JsonProperty("password")]
        public string Password { get; set; } = string.Empty;
    }
}