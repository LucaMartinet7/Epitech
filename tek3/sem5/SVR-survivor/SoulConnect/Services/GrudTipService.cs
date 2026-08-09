using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudTipService : ITipService
    {
        private readonly AppDbContext _context;

        public GrudTipService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IEnumerable<Tip>> GetAllTipsAsync()
        {
            return await _context.Tips.ToListAsync();
        }

        public async Task<Tip> GetTipByIdAsync(int id)
        {
            return await _context.Tips.FindAsync(id);
        }

        public async Task<Tip> AddTipAsync(Tip tip)
        {
            _context.Tips.Add(tip);
            await _context.SaveChangesAsync();
            return tip;
        }

        public async Task<Tip> UpdateTipAsync(Tip tip)
        {
            _context.Entry(tip).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return tip;
        }

        public async Task<bool> DeleteTipAsync(int id)
        {
            var tip = await _context.Tips.FindAsync(id);
            if (tip == null)
            {
                return false;
            }
            _context.Tips.Remove(tip);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
