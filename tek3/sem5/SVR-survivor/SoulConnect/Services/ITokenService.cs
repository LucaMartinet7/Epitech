using SoulConnect.Models;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface ITokenService
    {
        Task<Token> GetTokenAsync(string accessToken);
        Task<Token> AddTokenAsync(Token token);
        Task<Token> UpdateTokenAsync(Token token);
        Task<bool> DeleteTokenAsync(string accessToken);
    }
}
