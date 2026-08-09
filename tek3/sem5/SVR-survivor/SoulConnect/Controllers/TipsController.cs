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
    public class TipsController : ControllerBase
    {
        private readonly ITipService _tipService;

        public TipsController(ITipService tipService)
        {
            _tipService = tipService;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Tip>>> GetTips()
        {
            var tips = await _tipService.GetAllTipsAsync();
            return Ok(tips);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Tip>> GetTip(int id)
        {
            var tip = await _tipService.GetTipByIdAsync(id);
            if (tip == null)
            {
                return NotFound();
            }
            return Ok(tip);
        }

        [HttpPost]
        public async Task<ActionResult<Tip>> PostTip(Tip tip)
        {
            var createdTip = await _tipService.AddTipAsync(tip);
            return CreatedAtAction(nameof(GetTip), new { id = createdTip.Id }, createdTip);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutTip(int id, Tip tip)
        {
            if (id != tip.Id)
            {
                return BadRequest();
            }

            try
            {
                await _tipService.UpdateTipAsync(tip);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _tipService.GetTipByIdAsync(id) == null)
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
        public async Task<IActionResult> DeleteTip(int id)
        {
            var result = await _tipService.DeleteTipAsync(id);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
