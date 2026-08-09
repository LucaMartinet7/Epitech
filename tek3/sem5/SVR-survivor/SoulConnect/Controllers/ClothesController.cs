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
    public class ClothesController : ControllerBase
    {
        private readonly IClotheService _clotheService;

        public ClothesController(IClotheService clotheService)
        {
            _clotheService = clotheService;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Clothe>>> GetClothes()
        {
            var clothes = await _clotheService.GetAllClothesAsync();
            return Ok(clothes);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Clothe>> GetClothe(int id)
        {
            var clothe = await _clotheService.GetClotheByIdAsync(id);
            if (clothe == null)
            {
                return NotFound();
            }
            return Ok(clothe);
        }

        [HttpPost]
        public async Task<ActionResult<Clothe>> PostClothe(Clothe clothe)
        {
            var createdClothe = await _clotheService.AddClotheAsync(clothe);
            return CreatedAtAction(nameof(GetClothe), new { id = createdClothe.Id }, createdClothe);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutClothe(int id, Clothe clothe)
        {
            if (id != clothe.Id)
            {
                return BadRequest();
            }

            try
            {
                await _clotheService.UpdateClotheAsync(clothe);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _clotheService.GetClotheByIdAsync(id) == null)
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
        public async Task<IActionResult> DeleteClothe(int id)
        {
            var result = await _clotheService.DeleteClotheAsync(id);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
