#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    // Method to display account details
    void displayAccount() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount myAccount("1234567890", 500.00);

    // Display account details
    myAccount.displayAccount();

    // Perform deposit and withdrawal
    myAccount.deposit(200.00);
    myAccount.withdraw(100.00);
    myAccount.withdraw(700.00);  // Should trigger an error

    return 0;
}
