using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Clothe
    {
        public int Id { get; set; }

        [JsonProperty("type")]
        public string? Type { get; set; }
        public string? ImagePath { get; set; }
    }
}
