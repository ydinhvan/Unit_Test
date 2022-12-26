#pragma once

class Account
{
 public:
    // Constructor
    Account();

    // Method
    void deposit(double sum);
    void withdraw(double sum);
    double getBalance() const;
    void transfer(Account& to, double sum);
 private:
    // Attribute
    double mBalance;
};