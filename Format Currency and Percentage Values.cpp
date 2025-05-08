#include <iostream>
#include <iomanip>  // For manipulators
#include <string>

using namespace std;

int main() {
    string item = "Laptop";
    double price = 999.99;
    double taxRate = 0.075; // 7.5%
    double taxAmount = price * taxRate;
    double total = price + taxAmount;

    // Set output to fixed-point with 2 decimal places (currency format)
    cout << fixed << setprecision(2);

    cout << "Item: " << item << endl;

    cout << setw(15) << left << "Price:" 
         << "$" << price << endl;

    cout << setw(15) << left << "Tax Rate:" 
         << (taxRate * 100) << "%" << endl;

    cout << setw(15) << left << "Tax Amount:" 
         << "$" << taxAmount << endl;

    cout << setw(15) << left << "Total:" 
         << "$" << total << endl;

    return 0;
}
