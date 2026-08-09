using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Token
    {
        [Key]
        [JsonProperty("access_token")]
        public string? AccessToken { get; set; }
    }
}
