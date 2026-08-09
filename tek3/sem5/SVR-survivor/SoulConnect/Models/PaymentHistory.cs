using System.ComponentModel.DataAnnotations;
using Newtonsoft.Json;

namespace SoulConnect.Models
{
    public class PaymentHistory
    {
        [Key]
        public int Id { get; set; }
        [JsonProperty("date")]
        public DateTime? Date { get; set; }
        [JsonProperty("payment_method")]
        public string? PaymentMethod { get; set; }
        [JsonProperty("amount")]
        public decimal? Amount { get; set; }
        [JsonProperty("comment")]
        public string? Comment { get; set; }
        public int CustomerId { get; set; }
        public Customer? Customer { get; set; }
    }
}
