#include <iostream>
#include <iomanip>  // For setw
#include <string>

using namespace std;

int main() {
    // Table headers
    cout << left;  // Align everything to the left
    cout << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Age"
         << setw(12) << "Department" << endl;

    // Divider
    cout << "---------------------------------------------" << endl;

    // Table data
    cout << setw(10) << "101"
         << setw(15) << "Alice"
         << setw(10) << "28"
         << setw(12) << "HR" << endl;

    cout << setw(10) << "102"
         << setw(15) << "Bob"
         << setw(10) << "34"
         << setw(12) << "Finance" << endl;

    cout << setw(10) << "103"
         << setw(15) << "Charlie"
         << setw(10) << "25"
         << setw(12) << "IT" << endl;

    return 0;
}
