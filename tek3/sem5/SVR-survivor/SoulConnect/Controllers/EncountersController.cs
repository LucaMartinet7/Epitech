using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SoulConnect.Models;
using SoulConnect.Services;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SoulConnect.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class EncountersController : ControllerBase
    {
        private readonly IEncounterService _encounterService;

        public EncountersController(IEncounterService encounterService)
        {
            _encounterService = encounterService;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Encounter>>> GetEncounters()
        {
            var encounters = await _encounterService.GetAllEncountersAsync();
            return Ok(encounters);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Encounter>> GetEncounter(int id)
        {
            var encounter = await _encounterService.GetEncounterByIdAsync(id);
            if (encounter == null)
            {
                return NotFound();
            }
            return Ok(encounter);
        }

        [HttpPost]
        public async Task<ActionResult<Encounter>> PostEncounter(Encounter encounter)
        {
            var createdEncounter = await _encounterService.AddEncounterAsync(encounter);
            return CreatedAtAction(nameof(GetEncounter), new { id = createdEncounter.Id }, createdEncounter);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutEncounter(int id, Encounter encounter)
        {
            if (id != encounter.Id)
            {
                return BadRequest();
            }

            try
            {
                await _encounterService.UpdateEncounterAsync(encounter);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _encounterService.GetEncounterByIdAsync(id) == null)
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteEncounter(int id)
        {
            var result = await _encounterService.DeleteEncounterAsync(id);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
