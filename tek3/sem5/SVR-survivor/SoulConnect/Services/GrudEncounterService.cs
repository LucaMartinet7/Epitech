using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudEncounterService : IEncounterService
    {
        private readonly AppDbContext _context;

        public GrudEncounterService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IEnumerable<Encounter>> GetAllEncountersAsync()
        {
            return await _context.Encounters.ToListAsync();
        }

        public async Task<Encounter> GetEncounterByIdAsync(int id)
        {
            return await _context.Encounters.FindAsync(id);
        }

        public async Task<Encounter> AddEncounterAsync(Encounter encounter)
        {
            _context.Encounters.Add(encounter);
            await _context.SaveChangesAsync();
            return encounter;
        }

        public async Task<Encounter> UpdateEncounterAsync(Encounter encounter)
        {
            _context.Entry(encounter).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return encounter;
        }

        public async Task<bool> DeleteEncounterAsync(int id)
        {
            var encounter = await _context.Encounters.FindAsync(id);
            if (encounter == null)
            {
                return false;
            }
            _context.Encounters.Remove(encounter);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
