using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface IEncounterService
    {
        Task<IEnumerable<Encounter>> GetAllEncountersAsync();
        Task<Encounter> GetEncounterByIdAsync(int id);
        Task<Encounter> AddEncounterAsync(Encounter encounter);
        Task<Encounter> UpdateEncounterAsync(Encounter encounter);
        Task<bool> DeleteEncounterAsync(int id);
    }
}
