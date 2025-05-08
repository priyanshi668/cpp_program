#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;  // Private data member
    double balance;     // Private data member
    string accountHolderName;  // Private data member

public:
    // Constructor to initialize the account details
    Account(int accountNo, string name, double initialBalance) {
        accountNumber = accountNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    // Public method to get account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Public method to get account holder name
    string getAccountHolderName() const {
        return accountHolderName;
    }

    // Public method to get account balance
    double getBalance() const {
        return balance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Public method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance for withdrawal!" << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
    }

    // Public method to display account details
    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: $" << balance << endl;
    }
};

int main() {
    // Create an Account object
    Account myAccount(12345, "John Doe", 1000.0);

    // Display initial account details
    myAccount.displayAccountDetails();

    // Deposit money into the account
    myAccount.deposit(500.0);

    // Withdraw money from the account
    myAccount.withdraw(200.0);

    // Attempting invalid withdrawal (greater than balance)
    myAccount.withdraw(2000.0);

    // Display account details after transactions
    myAccount.displayAccountDetails();

    return 0;
}
