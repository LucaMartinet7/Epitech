using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface ITipService
    {
        Task<IEnumerable<Tip>> GetAllTipsAsync();
        Task<Tip> GetTipByIdAsync(int id);
        Task<Tip> AddTipAsync(Tip tip);
        Task<Tip> UpdateTipAsync(Tip tip);
        Task<bool> DeleteTipAsync(int id);
    }
}
