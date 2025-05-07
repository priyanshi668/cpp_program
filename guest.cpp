#include <iostream>
using namespace std;

// Function to print a greeting message with a default name
void greet(string name = "Guest") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    // Calling the function without any arguments (will use default name "Guest")
    greet();

    // Calling the function with a custom name
    greet("Alice");

    return 0;
}
