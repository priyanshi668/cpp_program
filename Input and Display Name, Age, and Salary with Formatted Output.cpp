#include <iostream>    // For cin, cout
#include <iomanip>     // For setw, fixed, setprecision

using namespace std;

int main() {
    string name;
    int age;
    double salary;

    // Read user input for name, age, and salary
    cout << "Enter your name: ";
    getline(cin, name);  // Use getline to allow spaces in name

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your salary: ";
    cin >> salary;

    // Display the information using formatted output
    cout << "\n--- User Information ---\n";
    cout << setw(20) << left << "Name:" << setw(20) << left << name << endl;
    cout << setw(20) << left << "Age:" << setw(20) << left << age << endl;
    cout << setw(20) << left << "Salary:" << setw(20) << left << fixed << setprecision(2) << salary << endl;

    return 0;
}
