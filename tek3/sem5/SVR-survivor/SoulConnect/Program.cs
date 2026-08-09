using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.Web;
using SoulConnect.Data;
using SoulConnect.Services;
using SoulConnect.Models;
using Microsoft.EntityFrameworkCore;
using Syncfusion.Blazor;
using System.Threading;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddRazorPages();
builder.Services.AddServerSideBlazor();
builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddSyncfusionBlazor();

builder.Services.AddSingleton<HttpClient>();
builder.Services.AddScoped<ApiService>();

builder.Services.AddScoped<CustomerService>();
builder.Services.AddScoped<CredentialService>();
builder.Services.AddScoped<EmployeeService>();
builder.Services.AddScoped<ClothesService>();
builder.Services.AddScoped<EventsService>();
builder.Services.AddScoped<EncountersService>();
builder.Services.AddScoped<PaymentHistoriesService>();
builder.Services.AddScoped<TipsService>();
builder.Services.AddScoped<TokenService>();

builder.Services.AddScoped<ICustomerService, GrudCustomerService>();
builder.Services.AddScoped<IEmployeeService, GrudEmployeeService>();
builder.Services.AddScoped<IPaymentHistoryService, GrudPaymentHistoryService>();
builder.Services.AddScoped<IEncounterService, GrudEncounterService>();
builder.Services.AddScoped<ITipService, GrudTipService>();
builder.Services.AddScoped<ITokenService, GrudTokenService>();
builder.Services.AddScoped<IEventsService, GrudEventsService>();
builder.Services.AddScoped<ICredentialsService, GrudCredentialsService>();

builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseMySql(builder.Configuration.GetConnectionString("DefaultConnection"),
    new MySqlServerVersion(new Version(8, 0, 30))));

builder.Services.Configure<ApiSettings>(builder.Configuration.GetSection("ApiSettings"));

var app = builder.Build();

app.UseSwagger();
app.UseSwaggerUI(c =>
{
    c.SwaggerEndpoint("/swagger/v1/swagger.json", "My API V1");
    c.RoutePrefix = "docs";
});

Syncfusion.Licensing.SyncfusionLicenseProvider.RegisterLicense("Ngo9BigBOggjHTQxAR8/V1NCaF1cWWhIfkx/WmFZfVpgcF9GYVZQQ2Y/P1ZhSXxXdkxiWX5acXBQRWVdVUc=");

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error");
    app.UseHsts();
}

void ScheduleAndRunApiService(IServiceScopeFactory scopeFactory)
{
    async Task ExecuteApiServiceCallsAsync()
    {
        using (var scope = scopeFactory.CreateScope())
        {
            var apiService = scope.ServiceProvider.GetRequiredService<ApiService>();

            int customerId = 1;

            await apiService.SaveCustomersAsync();
            await Task.Delay(30000);
            await apiService.SaveCredentialsAsync();
            await Task.Delay(30000);
            await apiService.SaveEmployeesAsync();
            await Task.Delay(30000);
            await apiService.SaveCustomerClothesAsync(customerId);
            await Task.Delay(30000);
            await apiService.SaveEventsAsync();
            await Task.Delay(30000);
            await apiService.SaveEncountersAsync();
            await Task.Delay(30000);
            await apiService.SaveAllCustomersPaymentHistoriesAsync();
            await Task.Delay(30000);
            await apiService.SaveTipsAsync();
            await Task.Delay(30000);
            await apiService.SaveTokenAsync();
        }
    }

    Task.Run(async () =>
    {
        await ExecuteApiServiceCallsAsync();
    }).GetAwaiter().GetResult();

    Timer timer = new Timer(async state =>
    {
        await ExecuteApiServiceCallsAsync();
    }, null, TimeSpan.FromHours(7), TimeSpan.FromHours(7));
}

using (var scope = app.Services.CreateScope())
{
    var dbContext = scope.ServiceProvider.GetRequiredService<AppDbContext>();
    dbContext.Database.Migrate();

    ScheduleAndRunApiService(app.Services.GetRequiredService<IServiceScopeFactory>());
}

app.UseHttpsRedirection();

app.UseStaticFiles();

app.UseRouting();

app.MapRazorPages();
app.MapBlazorHub();
app.MapFallbackToPage("/_Host");

app.Run();
