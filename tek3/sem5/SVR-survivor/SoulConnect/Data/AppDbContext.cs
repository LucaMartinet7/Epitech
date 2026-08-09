using Microsoft.EntityFrameworkCore;
using SoulConnect.Models;
using System.Collections.Generic;

namespace SoulConnect.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options)
            : base(options)
        {
        }

        public DbSet<Credentials> Credentials { get; set; }
        public DbSet<Customer> Customers { get; set; }
        public DbSet<Employee> Employees { get; set; }
        public DbSet<Clothe> Clothes { get; set; }
        public DbSet<Encounter> Encounters { get; set; }
        public DbSet<Events> Events { get; set; }
        public DbSet<PaymentHistory> PaymentHistories { get; set; }
        public DbSet<Tip> Tips { get; set; }
        public DbSet<Token> Tokens { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Credentials>().ToTable("credentials");
            modelBuilder.Entity<Customer>().ToTable("customers");
            modelBuilder.Entity<Employee>().ToTable("employees");
            modelBuilder.Entity<Clothe>().ToTable("clothes");
            modelBuilder.Entity<Encounter>().ToTable("encounters");
            modelBuilder.Entity<Events>().ToTable("events");
            modelBuilder.Entity<PaymentHistory>().ToTable("payment_histories");
            modelBuilder.Entity<Tip>().ToTable("tips");
            modelBuilder.Entity<Token>().ToTable("tokens");
        }

        // Ensure tables are created only if they do not exist
        public void EnsureDatabaseCreated()
        {
            var tableNames = new[]
            {
                "credentials", "customers", "employees", "clothes", "encounters",
                "events", "payment_histories", "tips", "tokens"
            };

            foreach (var tableName in tableNames)
            {
                var tableExists = this.Database.ExecuteSqlRaw($@"
                    SELECT COUNT(*) 
                    FROM information_schema.tables 
                    WHERE table_schema = DATABASE() 
                    AND table_name = '{tableName}'
                ");

                // If the table does not exist (COUNT == 0), create it
                if (tableExists == 0)
                {
                    CreateTable(tableName);
                }
            }
        }

        // Create tables based on their names
        private void CreateTable(string tableName)
        {
            switch (tableName)
            {
                case "credentials":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE credentials (
                        Email VARCHAR(255) PRIMARY KEY,
                        Password VARCHAR(255) NOT NULL
                    );
                ");
                    break;

                case "customers":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE customers (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Email VARCHAR(255),
                        Name VARCHAR(255),
                        Surname VARCHAR(255),
                        BirthDate DATETIME,
                        Gender VARCHAR(10),
                        Description TEXT,
                        AstrologicalSign VARCHAR(50),
                        PhoneNumber VARCHAR(20),
                        Address TEXT
                    );
                ");
                    break;

                case "employees":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE employees (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Email VARCHAR(255) NOT NULL,
                        Name VARCHAR(255) NOT NULL,
                        Surname VARCHAR(255) NOT NULL,
                        BirthDate DATETIME,
                        Gender VARCHAR(10) NOT NULL,
                        Work VARCHAR(255)
                    );
                ");
                    break;

                case "clothes":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE clothes (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Type VARCHAR(255),
                        ImagePath VARCHAR(255)
                    );
                ");
                    break;

                case "encounters":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE encounters (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        CustomerId INT,
                        Date DATETIME,
                        Rating INT,
                        Comment TEXT,
                        Source VARCHAR(255),
                        FOREIGN KEY (CustomerId) REFERENCES customers(Id)
                    );
                ");
                    break;

                case "events":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE events (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Name VARCHAR(255),
                        Date DATETIME,
                        Duration INT,
                        MaxParticipants INT,
                        LocationX VARCHAR(255),
                        LocationY VARCHAR(255),
                        Type VARCHAR(255),
                        EmployeeId INT,
                        LocationName VARCHAR(255),
                        FOREIGN KEY (EmployeeId) REFERENCES employees(Id)
                    );
                ");
                    break;

                case "payment_histories":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE payment_histories (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Date DATETIME,
                        PaymentMethod VARCHAR(255),
                        Amount DECIMAL(18, 2),
                        Comment TEXT,
                        CustomerId INT,
                        FOREIGN KEY (CustomerId) REFERENCES customers(Id) ON DELETE CASCADE
                    );
                ");
                    break;

                case "tips":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE tips (
                        Id INT AUTO_INCREMENT PRIMARY KEY,
                        Title VARCHAR(255),
                        TipContent TEXT
                    );
                ");
                    break;

                case "tokens":
                    this.Database.ExecuteSqlRaw(@"
                    CREATE TABLE tokens (
                        AccessToken TEXT
                    );
                ");
                    break;
            }
        }
    }
}
