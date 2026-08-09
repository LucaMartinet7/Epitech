using Microsoft.EntityFrameworkCore;
using SoulConnect.Data;
using SoulConnect.Models;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public class GrudTokenService : ITokenService
    {
        private readonly AppDbContext _context;

        public GrudTokenService(AppDbContext context)
        {
            _context = context;
        }

        public async Task<Token> GetTokenAsync(string accessToken)
        {
            return await _context.Tokens.FindAsync(accessToken);
        }

        public async Task<Token> AddTokenAsync(Token token)
        {
            _context.Tokens.Add(token);
            await _context.SaveChangesAsync();
            return token;
        }

        public async Task<Token> UpdateTokenAsync(Token token)
        {
            _context.Entry(token).State = EntityState.Modified;
            await _context.SaveChangesAsync();
            return token;
        }

        public async Task<bool> DeleteTokenAsync(string accessToken)
        {
            var token = await _context.Tokens.FindAsync(accessToken);
            if (token == null)
            {
                return false;
            }
            _context.Tokens.Remove(token);
            await _context.SaveChangesAsync();
            return true;
        }
    }
}
