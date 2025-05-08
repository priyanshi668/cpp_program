#include <iostream>    // For cin, cout
#include <iomanip>     // For manipulators like setw, setprecision
#include <string>      // For string manipulation

using namespace std;

int main() {
    // Sample data to display in the table
    string headers[] = {"ID", "Name", "Age", "Salary"};
    int ids[] = {101, 102, 103, 104};
    string names[] = {"Alice", "Bob", "Charlie", "David"};
    int ages[] = {25, 30, 35, 40};
    double salaries[] = {55000.50, 60000.75, 75000.25, 80000.60};

    // Output table header
    cout << left;
    cout << setw(10) << headers[0]
         << setw(20) << headers[1]
         << setw(10) << headers[2]
         << setw(15) << headers[3] << endl;
    cout << "------------------------------------------------------------" << endl;

    // Output table data with formatted values
    for (int i = 0; i < 4; i++) {
        cout << setw(10) << ids[i]
             << setw(20) << names[i]
             << setw(10) << ages[i]
             << setw(15) << fixed << setprecision(2) << salaries[i] << endl;
    }

    return 0;
}
