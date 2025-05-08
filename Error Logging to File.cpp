#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void logError(const string& message) {
    ofstream logFile("error_log.txt", ios::app); // Open in append mode
    if (!logFile) {
        cerr << "Failed to open log file." << endl;
        return;
    }
    logFile << "ERROR: " << message << endl;
    logFile.close();
}

int main() {
    int a, b;

    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    if (b == 0) {
        string errorMsg = "Division by zero attempted (a = " + to_string(a) + ", b = 0)";
        cerr << "Error: Division by zero is not allowed." << endl;
        logError(errorMsg);
    } else {
        cout << "Result of a / b = " << (a / b) << endl;
    }

    cout << "Program finished. Check 'error_log.txt' for any error logs." << endl;

    return 0;
}
