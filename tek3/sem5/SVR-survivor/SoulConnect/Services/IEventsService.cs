using SoulConnect.Models;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Services
{
    public interface IEventsService
    {
        Task<IEnumerable<Events>> GetAllEventsAsync();
        Task<Events> GetEventByIdAsync(int id);
        Task<Events> AddEventAsync(Events ev);
        Task<Events> UpdateEventAsync(Events ev);
        Task<bool> DeleteEventAsync(int id);
    }
}
