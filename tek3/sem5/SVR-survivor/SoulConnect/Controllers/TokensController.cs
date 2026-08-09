using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SoulConnect.Models;
using SoulConnect.Services;
using System.Threading.Tasks;

namespace SoulConnect.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class TokensController : ControllerBase
    {
        private readonly ITokenService _tokenService;

        public TokensController(ITokenService tokenService)
        {
            _tokenService = tokenService;
        }

        [HttpGet("{accessToken}")]
        public async Task<ActionResult<Token>> GetToken(string accessToken)
        {
            var token = await _tokenService.GetTokenAsync(accessToken);
            if (token == null)
            {
                return NotFound();
            }
            return Ok(token);
        }

        [HttpPost]
        public async Task<ActionResult<Token>> PostToken(Token token)
        {
            var createdToken = await _tokenService.AddTokenAsync(token);
            return CreatedAtAction(nameof(GetToken), new { accessToken = createdToken.AccessToken }, createdToken);
        }

        [HttpPut("{accessToken}")]
        public async Task<IActionResult> PutToken(string accessToken, Token token)
        {
            if (accessToken != token.AccessToken)
            {
                return BadRequest();
            }

            try
            {
                await _tokenService.UpdateTokenAsync(token);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _tokenService.GetTokenAsync(accessToken) == null)
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

        [HttpDelete("{accessToken}")]
        public async Task<IActionResult> DeleteToken(string accessToken)
        {
            var result = await _tokenService.DeleteTokenAsync(accessToken);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
