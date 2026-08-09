using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class Encounter
    {
        [Key]
        public int Id { get; set; }

        [JsonProperty("customer_id")]
        public int CustomerId { get; set; }

        [JsonProperty("date")]
        public DateTime? Date { get; set; }

        [JsonProperty("rating")]
        public int? Rating { get; set; }

        [JsonProperty("comment")]
        public string? Comment { get; set; }

        [JsonProperty("source")]
        public string? Source { get; set; }

        public Customer? Customer { get; set; }
    }
}
