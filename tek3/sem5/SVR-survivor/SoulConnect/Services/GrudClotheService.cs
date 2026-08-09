using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudClotheService : IClotheService
    {
        private readonly AppDbContext _context;

        public GrudClotheService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IEnumerable<Clothe>> GetAllClothesAsync()
        {
            return await _context.Clothes.ToListAsync();
        }

        public async Task<Clothe> GetClotheByIdAsync(int id)
        {
            return await _context.Clothes.FindAsync(id);
        }

        public async Task<Clothe> AddClotheAsync(Clothe clothe)
        {
            _context.Clothes.Add(clothe);
            await _context.SaveChangesAsync();
            return clothe;
        }

        public async Task<Clothe> UpdateClotheAsync(Clothe clothe)
        {
            _context.Entry(clothe).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return clothe;
        }

        public async Task<bool> DeleteClotheAsync(int id)
        {
            var clothe = await _context.Clothes.FindAsync(id);
            if (clothe == null)
            {
                return false;
            }
            _context.Clothes.Remove(clothe);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
