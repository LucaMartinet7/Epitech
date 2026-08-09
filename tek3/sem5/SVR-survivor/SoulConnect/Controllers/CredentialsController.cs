using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SoulConnect.Models;
using SoulConnect.Services;
using System.Threading.Tasks;

namespace SoulConnect.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class CredentialsController : ControllerBase
    {
        private readonly ICredentialsService _credentialsService;

        public CredentialsController(ICredentialsService credentialsService)
        {
            _credentialsService = credentialsService;
        }

        [HttpGet("{email}")]
        public async Task<ActionResult<Credentials>> GetCredentials(string email)
        {
            var credentials = await _credentialsService.GetCredentialsByEmailAsync(email);
            if (credentials == null)
            {
                return NotFound();
            }
            return Ok(credentials);
        }

        [HttpPost]
        public async Task<ActionResult<Credentials>> PostCredentials(Credentials credentials)
        {
            var createdCredentials = await _credentialsService.AddCredentialsAsync(credentials);
            return CreatedAtAction(nameof(GetCredentials), new { email = createdCredentials.Email }, createdCredentials);
        }

        [HttpPut("{email}")]
        public async Task<IActionResult> PutCredentials(string email, Credentials credentials)
        {
            if (email != credentials.Email)
            {
                return BadRequest();
            }

            try
            {
                await _credentialsService.UpdateCredentialsAsync(credentials);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _credentialsService.GetCredentialsByEmailAsync(email) == null)
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

        [HttpDelete("{email}")]
        public async Task<IActionResult> DeleteCredentials(string email)
        {
            var result = await _credentialsService.DeleteCredentialsAsync(email);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
