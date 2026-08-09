using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface IClotheService
    {
        Task<IEnumerable<Clothe>> GetAllClothesAsync();
        Task<Clothe> GetClotheByIdAsync(int id);
        Task<Clothe> AddClotheAsync(Clothe clothe);
        Task<Clothe> UpdateClotheAsync(Clothe clothe);
        Task<bool> DeleteClotheAsync(int id);
    }
}
