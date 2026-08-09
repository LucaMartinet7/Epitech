using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Tip
    {
        [Key]
        public int Id { get; set; }
        [JsonProperty("title")]
        public string? Title { get; set; }
        [JsonProperty("tip")]
        public string? TipContent { get; set; }
    }
}
