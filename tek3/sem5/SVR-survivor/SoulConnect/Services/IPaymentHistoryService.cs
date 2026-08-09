using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface IPaymentHistoryService
    {
        Task<IEnumerable<PaymentHistory>> GetAllPaymentHistoriesAsync();
        Task<PaymentHistory> GetPaymentHistoryByIdAsync(int id);
        Task<PaymentHistory> AddPaymentHistoryAsync(PaymentHistory paymentHistory);
        Task<PaymentHistory> UpdatePaymentHistoryAsync(PaymentHistory paymentHistory);
        Task<bool> DeletePaymentHistoryAsync(int id);
    }
}
