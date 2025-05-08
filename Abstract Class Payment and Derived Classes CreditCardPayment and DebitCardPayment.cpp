#include <iostream>
#include <string>
using namespace std;

// Abstract base class Payment
class Payment {
public:
    // Pure virtual function to process payment
    virtual void processPayment() const = 0;

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Payment() {}
};

// Derived class CreditCardPayment
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    double amount;

public:
    // Constructor to initialize CreditCardPayment details
    CreditCardPayment(string card, double amt) : cardNumber(card), amount(amt) {}

    // Implement the processPayment function for CreditCardPayment
    void processPayment() const override {
        cout << "Processing Credit Card Payment:" << endl;
        cout << "Card Number: " << cardNumber << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Payment Successful via Credit Card." << endl;
    }
};

// Derived class DebitCardPayment
class DebitCardPayment : public Payment {
private:
    string cardNumber;
    double amount;

public:
    // Constructor to initialize DebitCardPayment details
    DebitCardPayment(string card, double amt) : cardNumber(card), amount(amt) {}

    // Implement the processPayment function for DebitCardPayment
    void processPayment() const override {
        cout << "Processing Debit Card Payment:" << endl;
        cout << "Card Number: " << cardNumber << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Payment Successful via Debit Card." << endl;
    }
};

int main() {
    // Create objects of CreditCardPayment and DebitCardPayment
    Payment* payment1 = new CreditCardPayment("1234-5678-9876-5432", 150.75);
    Payment* payment2 = new DebitCardPayment("9876-5432-1234-5678", 75.50);

    // Process the payments
    payment1->processPayment();  // Calls CreditCardPayment's processPayment
    cout << endl;
    payment2->processPayment();  // Calls DebitCardPayment's processPayment

    // Deallocate memory
    delete payment1;
    delete payment2;

    return 0;
}
