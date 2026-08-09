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
    public class PaymentHistoriesController : ControllerBase
    {
        private readonly IPaymentHistoryService _paymentHistoryService;

        public PaymentHistoriesController(IPaymentHistoryService paymentHistoryService)
        {
            _paymentHistoryService = paymentHistoryService;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<PaymentHistory>>> GetPaymentHistories()
        {
            var paymentHistories = await _paymentHistoryService.GetAllPaymentHistoriesAsync();
            return Ok(paymentHistories);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<PaymentHistory>> GetPaymentHistory(int id)
        {
            var paymentHistory = await _paymentHistoryService.GetPaymentHistoryByIdAsync(id);
            if (paymentHistory == null)
            {
                return NotFound();
            }
            return Ok(paymentHistory);
        }

        [HttpPost]
        public async Task<ActionResult<PaymentHistory>> PostPaymentHistory(PaymentHistory paymentHistory)
        {
            var createdPaymentHistory = await _paymentHistoryService.AddPaymentHistoryAsync(paymentHistory);
            return CreatedAtAction(nameof(GetPaymentHistory), new { id = createdPaymentHistory.Id }, createdPaymentHistory);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutPaymentHistory(int id, PaymentHistory paymentHistory)
        {
            if (id != paymentHistory.Id)
            {
                return BadRequest();
            }

            try
            {
                await _paymentHistoryService.UpdatePaymentHistoryAsync(paymentHistory);
            }
            catch (DbUpdateConcurrencyException)
            {
                if (await _paymentHistoryService.GetPaymentHistoryByIdAsync(id) == null)
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
        public async Task<IActionResult> DeletePaymentHistory(int id)
        {
            var result = await _paymentHistoryService.DeletePaymentHistoryAsync(id);
            if (!result)
            {
                return NotFound();
            }
            return NoContent();
        }
    }
}
