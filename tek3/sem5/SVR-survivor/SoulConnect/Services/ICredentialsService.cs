using SoulConnect.Models;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface ICredentialsService
    {
        Task<Credentials> GetCredentialsByEmailAsync(string email);
        Task<Credentials> AddCredentialsAsync(Credentials credentials);
        Task<Credentials> UpdateCredentialsAsync(Credentials credentials);
        Task<bool> DeleteCredentialsAsync(string email);
    }
}
