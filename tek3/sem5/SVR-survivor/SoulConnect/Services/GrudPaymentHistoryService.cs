using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudPaymentHistoryService : IPaymentHistoryService
    {
        private readonly AppDbContext _context;

        public GrudPaymentHistoryService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IEnumerable<PaymentHistory>> GetAllPaymentHistoriesAsync()
        {
            return await _context.PaymentHistories.ToListAsync();
        }

        public async Task<PaymentHistory> GetPaymentHistoryByIdAsync(int id)
        {
            return await _context.PaymentHistories.FindAsync(id);
        }

        public async Task<PaymentHistory> AddPaymentHistoryAsync(PaymentHistory paymentHistory)
        {
            _context.PaymentHistories.Add(paymentHistory);
            await _context.SaveChangesAsync();
            return paymentHistory;
        }

        public async Task<PaymentHistory> UpdatePaymentHistoryAsync(PaymentHistory paymentHistory)
        {
            _context.Entry(paymentHistory).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return paymentHistory;
        }

        public async Task<bool> DeletePaymentHistoryAsync(int id)
        {
            var paymentHistory = await _context.PaymentHistories.FindAsync(id);
            if (paymentHistory == null)
            {
                return false;
            }
            _context.PaymentHistories.Remove(paymentHistory);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
