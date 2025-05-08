#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int choice;
        cout << "Choose an error to simulate:\n";
        cout << "1. Divide by zero\n";
        cout << "2. Out of range\n";
        cout << "3. String error\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            throw runtime_error("Division by zero error.");
        } else if (choice == 2) {
            throw out_of_range("Index out of range.");
        } else if (choice == 3) {
            throw string("Custom string exception.");
        } else {
            cout << "No exception selected.\n";
        }

    } catch (const runtime_error& e) {
        cout << "Caught a runtime_error: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << "Caught an out_of_range exception: " << e.what() << endl;
    } catch (const string& e) {
        cout << "Caught a string exception: " << e << endl;
    } catch (...) {
        cout << "Caught an unknown exception." << endl;
    }

    return 0;
}
