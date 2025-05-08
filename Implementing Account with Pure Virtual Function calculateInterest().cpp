#include <iostream>
using namespace std;

// Abstract base class Account with a pure virtual function
class Account {
protected:
    double balance;

public:
    // Constructor to initialize account balance
    Account(double initialBalance) : balance(initialBalance) {}

    // Pure virtual function for calculating interest
    virtual double calculateInterest() const = 0;

    // Virtual destructor to ensure proper cleanup
    virtual ~Account() {}
};

// Derived class SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor to initialize balance and interest rate
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    // Implementing calculateInterest for SavingsAccount
    double calculateInterest() const override {
        return balance * interestRate / 100;
    }
};

// Derived class CurrentAccount
class CurrentAccount : public Account {
public:
    // Constructor to initialize balance
    CurrentAccount(double initialBalance)
        : Account(initialBalance) {}

    // Implementing calculateInterest for CurrentAccount (returns zero interest)
    double calculateInterest() const override {
        return 0.0;  // Current accounts do not earn interest
    }
};

int main() {
    // Creating objects of SavingsAccount and CurrentAccount
    Account* account1 = new SavingsAccount(1000.0, 5.0);  // SavingsAccount with 5% interest rate
    Account* account2 = new CurrentAccount(1500.0);       // CurrentAccount with no interest

    // Displaying interest for both accounts
    cout << "Interest on SavingsAccount: " << account1->calculateInterest() << endl;
    cout << "Interest on CurrentAccount: " << account2->calculateInterest() << endl;

    // Deallocate memory
    delete account1;
    delete account2;

    return 0;
}
