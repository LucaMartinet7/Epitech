using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Threading.Tasks;
using Microsoft.Extensions.Options;
using Newtonsoft.Json;
using SoulConnect.Models;

namespace SoulConnect.Services
{
    public class PaymentHistoriesService
    {
        private readonly HttpClient _httpClient;
        private readonly ApiSettings _apiSettings;
        private readonly CustomerService _customerService;

        public PaymentHistoriesService(HttpClient httpClient, IOptions<ApiSettings> apiSettings, CustomerService customerService)
        {
            _httpClient = httpClient;
            _apiSettings = apiSettings.Value;
            _customerService = customerService;
            _httpClient.BaseAddress = new Uri(_apiSettings.BaseUrl);
        }

        public async Task<List<PaymentHistory>> GetPaymentHistoriesAsync(int customerId)
        {
            Console.WriteLine($"Starting to fetch payment history for customer ID: {customerId}...");

            try
            {
                _httpClient.DefaultRequestHeaders.Clear();
                _httpClient.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
                _httpClient.DefaultRequestHeaders.Add("X-Group-Authorization", _apiSettings.GroupAuthorization);
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", _apiSettings.AccessToken);

                Console.WriteLine($"Sending request to /api/customers/{customerId}/payments_history...");
                var response = await _httpClient.GetAsync($"customers/{customerId}/payments_history");
                response.EnsureSuccessStatusCode();
                Console.WriteLine("Successfully received response from payment history API.");

                var content = await response.Content.ReadAsStringAsync();
                var paymentHistories = JsonConvert.DeserializeObject<List<PaymentHistory>>(content);
                Console.WriteLine($"Fetched {paymentHistories.Count} payment histories for customer ID: {customerId}.");

                foreach (var paymentHistory in paymentHistories)
                {
                    paymentHistory.CustomerId = customerId;
                }

                return paymentHistories;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching payment history for customer ID {customerId}: {ex.Message}");
                return new List<PaymentHistory>();
            }
        }

        public async Task<List<PaymentHistory>> GetAllCustomersPaymentHistoriesAsync()
        {
            var allPaymentHistories = new List<PaymentHistory>();
            try
            {
                var customers = await _customerService.GetCustomersAsync();
                Console.WriteLine($"Fetched {customers.Count} customers.");

                foreach (var customer in customers)
                {
                    Console.WriteLine($"Fetching payment history for customer ID: {customer.Id}...");
                    var customerPaymentHistories = await GetPaymentHistoriesAsync(customer.Id);

                    allPaymentHistories.AddRange(customerPaymentHistories);
                }

                Console.WriteLine("Completed fetching payment histories for all customers.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error fetching payment histories for all customers: {ex.Message}");
            }

            return allPaymentHistories;
        }
    }
}
