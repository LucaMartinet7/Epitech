using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Newtonsoft.Json;
using SoulConnect.Data;
using SoulConnect.Models;
using SoulConnect.Services;

namespace SoulConnect.Services
{
    public class ApiService
    {
        private readonly CustomerService _customerService;
        private readonly CredentialService _credentialService;
        private readonly EmployeeService _employeeService;
        private readonly ClothesService _clothesService;
        private readonly EncountersService _encountersService;
        private readonly EventsService _eventsService;
        private readonly PaymentHistoriesService _paymentHistoriesService;
        private readonly TipsService _tipsService;
        private readonly TokenService _tokenService;
        private readonly AppDbContext _dbContext;

        public ApiService(CustomerService customerService, CredentialService credentialService, EmployeeService employeeService,
                          ClothesService clothesService, EncountersService encountersService, EventsService eventsService,
                          PaymentHistoriesService paymentHistoriesService, TipsService tipsService, TokenService tokenService,
                          AppDbContext dbContext)
        {
            _customerService = customerService;
            _credentialService = credentialService;
            _employeeService = employeeService;
            _clothesService = clothesService;
            _encountersService = encountersService;
            _eventsService = eventsService;
            _paymentHistoriesService = paymentHistoriesService;
            _tipsService = tipsService;
            _tokenService = tokenService;
            _dbContext = dbContext;
        }

        public async Task SaveCustomersAsync()
        {
            await Task.Delay(30000);
            try
            {
                var customers = await _customerService.GetCustomersAsync();

                foreach (var customer in customers)
                {
                    var existingCustomer = await _dbContext.Customers
                        .SingleOrDefaultAsync(c => c.Id == customer.Id);

                    if (existingCustomer != null)
                    {
                        _dbContext.Entry(existingCustomer).CurrentValues.SetValues(customer);
                    }
                    else
                    {
                        _dbContext.Customers.Add(customer);
                    }

                    await SaveCustomerClothesAsync(customer.Id);
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving customers: {ex.Message}");
            }
        }

                public async Task SaveCredentialsAsync()
        {
            await Task.Delay(30000);
            try
            {
                var credentials = await _credentialService.GetCredentialsAsync();

                foreach (var credential in credentials)
                {
                    var existingCredential = await _dbContext.Credentials
                        .SingleOrDefaultAsync(c => c.Email == credential.Email);

                    if (existingCredential != null)
                    {
                        _dbContext.Entry(existingCredential).CurrentValues.SetValues(credential);
                    }
                    else
                    {
                        _dbContext.Credentials.Add(credential);
                    }
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving credentials: {ex.Message}");
            }
        }

        public async Task SaveEmployeesAsync()
        {
            await Task.Delay(30000);
            try
            {
                var employees = await _employeeService.GetEmployeesAsync();

                if (employees == null || !employees.Any())
                {
                    Console.WriteLine("No employees to save.");
                    return;
                }

                foreach (var employee in employees)
                {
                    var existingEmployee = await _dbContext.Employees
                        .SingleOrDefaultAsync(e => e.Id == employee.Id);

                    if (existingEmployee != null)
                    {
                        _dbContext.Entry(existingEmployee).CurrentValues.SetValues(employee);
                    }
                    else
                    {
                        _dbContext.Employees.Add(employee);
                    }
                }

                await _dbContext.SaveChangesAsync();
                Console.WriteLine("Employees saved successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving employees: {ex.Message}");
            }
        }

        public async Task SaveCustomerClothesAsync(int customerId)
        {
            await Task.Delay(30000);
            try
            {
                var clothes = await _clothesService.GetCustomerClothesAsync(customerId);

                foreach (var clothe in clothes)
                {
                    var existingClothe = await _dbContext.Clothes
                        .SingleOrDefaultAsync(c => c.Id == clothe.Id);

                    if (existingClothe != null)
                    {
                        _dbContext.Entry(existingClothe).CurrentValues.SetValues(clothe);
                    }
                    else
                    {
                        _dbContext.Clothes.Add(clothe);
                    }
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving clothes for customer {customerId}: {ex.Message}");
            }
        }

        public async Task SaveEncountersAsync()
        {
            await Task.Delay(30000);
            try
            {
                var encounters = await _encountersService.GetEncountersAsync();

                foreach (var encounter in encounters)
                {
                    var existingEncounter = await _dbContext.Encounters
                        .SingleOrDefaultAsync(e => e.Id == encounter.Id);

                    if (existingEncounter != null)
                    {
                        _dbContext.Entry(existingEncounter).CurrentValues.SetValues(encounter);
                    }
                    else
                    {
                        _dbContext.Encounters.Add(encounter);
                    }
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving encounters: {ex.Message}");
            }
        }

        public async Task SaveEventsAsync()
        {
            await Task.Delay(30000);
            try
            {
                var events = await _eventsService.GetEventsAsync();

                foreach (var ev in events)
                {
                    var existingEvent = await _dbContext.Events
                        .SingleOrDefaultAsync(e => e.Id == ev.Id);

                    if (existingEvent != null)
                    {
                        _dbContext.Entry(existingEvent).CurrentValues.SetValues(ev);
                    }
                    else
                    {
                        _dbContext.Events.Add(ev);
                    }
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving events: {ex.Message}");
            }
        }

        public async Task SaveAllCustomersPaymentHistoriesAsync()
        {
            await Task.Delay(30000);
            try
            {
                var paymentHistories = await _paymentHistoriesService.GetAllCustomersPaymentHistoriesAsync();

                foreach (var paymentHistory in paymentHistories)
                {
                    var existingPaymentHistory = await _dbContext.PaymentHistories
                        .SingleOrDefaultAsync(p => p.Id == paymentHistory.Id);

                    if (existingPaymentHistory != null)
                    {
                        _dbContext.Entry(existingPaymentHistory).CurrentValues.SetValues(paymentHistory);
                    }
                    else
                    {
                        _dbContext.PaymentHistories.Add(paymentHistory);
                    }
                }

                await _dbContext.SaveChangesAsync();
                Console.WriteLine("All customers' payment histories saved successfully.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving all customers' payment histories: {ex.Message}");
            }
        }

        public async Task SaveTipsAsync()
        {
            await Task.Delay(30000);
            try
            {
                var tips = await _tipsService.GetTipsAsync();

                foreach (var tip in tips)
                {
                    var existingTip = await _dbContext.Tips
                        .SingleOrDefaultAsync(t => t.Id == tip.Id);

                    if (existingTip != null)
                    {
                        _dbContext.Entry(existingTip).CurrentValues.SetValues(tip);
                    }
                    else
                    {
                        _dbContext.Tips.Add(tip);
                    }
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving tips: {ex.Message}");
            }
        }

        public async Task SaveTokenAsync()
        {
            await Task.Delay(30000);
            try
            {
                var token = await _tokenService.GetTokenAsync();

                var existingToken = await _dbContext.Tokens
                    .SingleOrDefaultAsync(t => t.AccessToken == token.AccessToken);

                if (existingToken != null)
                {
                    _dbContext.Entry(existingToken).CurrentValues.SetValues(token);
                }
                else
                {
                    _dbContext.Tokens.Add(token);
                }

                await _dbContext.SaveChangesAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error saving token: {ex.Message}");
            }
        }
    }
}
