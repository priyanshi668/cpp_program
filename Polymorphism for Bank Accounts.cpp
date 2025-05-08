#include <iostream>
#include <string>
using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) : accountHolder(name), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    virtual void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string name, double initialBalance) : BankAccount(name, initialBalance) {}

    void deposit(double amount) override {
        // Savings account has a fixed deposit logic (example: 2% interest on deposit)
        amount += amount * 0.02; // Apply 2% interest on deposit
        BankAccount::deposit(amount);
    }

    void display() override {
        cout << "Savings Account Info:" << endl;
        BankAccount::display();
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string name, double initialBalance) : BankAccount(name, initialBalance) {}

    void withdraw(double amount) override {
        // Checking account allows withdrawal even if balance is 0, but with a fee
        if (amount > balance) {
            cout << "Insufficient funds. A $10 fee will be charged." << endl;
            balance -= 10; // Charge fee
        }
        BankAccount::withdraw(amount);
    }

    void display() override {
        cout << "Checking Account Info:" << endl;
        BankAccount::display();
    }
};

// Main function: Menu-driven interface for managing accounts
int main() {
    int choice;
    BankAccount* account = nullptr;
    string name;
    double balance;

    while (true) {
        cout << "\nBank Account Management System\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Deposit to Account\n";
        cout << "4. Withdraw from Account\n";
        cout << "5. Display Account Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: $";
                cin >> balance;
                account = new SavingsAccount(name, balance);
                cout << "Savings Account created successfully.\n";
                break;

            case 2:
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: $";
                cin >> balance;
                account = new CheckingAccount(name, balance);
                cout << "Checking Account created successfully.\n";
                break;

            case 3:
                if (account) {
                    double amount;
                    cout << "Enter deposit amount: $";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "No account selected.\n";
                }
                break;

            case 4:
                if (account) {
                    double amount;
                    cout << "Enter withdrawal amount: $";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "No account selected.\n";
                }
                break;

            case 5:
                if (account) {
                    account->display();
                } else {
                    cout << "No account selected.\n";
                }
                break;

            case 6:
                cout << "Exiting the program.\n";
                delete account;  // Free the dynamically allocated account memory
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
