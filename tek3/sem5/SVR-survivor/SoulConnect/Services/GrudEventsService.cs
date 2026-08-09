using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudEventsService : IEventsService
    {
        private readonly AppDbContext _context;

        public GrudEventsService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<IEnumerable<Events>> GetAllEventsAsync()
        {
            return await _context.Events.ToListAsync();
        }

        public async Task<Events> GetEventByIdAsync(int id)
        {
            return await _context.Events.FindAsync(id);
        }

        public async Task<Events> AddEventAsync(Events ev)
        {
            _context.Events.Add(ev);
            await _context.SaveChangesAsync();
            return ev;
        }

        public async Task<Events> UpdateEventAsync(Events ev)
        {
            _context.Entry(ev).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return ev;
        }

        public async Task<bool> DeleteEventAsync(int id)
        {
            var ev = await _context.Events.FindAsync(id);
            if (ev == null)
            {
                return false;
            }
            _context.Events.Remove(ev);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
