using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudCredentialsService : ICredentialsService
    {
        private readonly AppDbContext _context;

        public GrudCredentialsService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<Credentials> GetCredentialsByEmailAsync(string email)
        {
            return await _context.Credentials.FindAsync(email);
        }

        public async Task<Credentials> AddCredentialsAsync(Credentials credentials)
        {
            _context.Credentials.Add(credentials);
            await _context.SaveChangesAsync();
            return credentials;
        }

        public async Task<Credentials> UpdateCredentialsAsync(Credentials credentials)
        {
            _context.Entry(credentials).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return credentials;
        }

        public async Task<bool> DeleteCredentialsAsync(string email)
        {
            var credentials = await _context.Credentials.FindAsync(email);
            if (credentials == null)
            {
                return false;
            }
            _context.Credentials.Remove(credentials);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
