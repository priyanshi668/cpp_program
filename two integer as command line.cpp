#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int main(int argc, char* argv[]) {
    // Check if two command line arguments are passed
    if (argc != 3) {
        cout << "Please provide two integers as command line arguments." << endl;
        return 1; // Exit with an error code if arguments are missing
    }

    // Convert the command line arguments to integers
    int num1 = atoi(argv[1]); // Convert the first argument to an integer
    int num2 = atoi(argv[2]); // Convert the second argument to an integer

    // Calculate and print the sum
    int sum = num1 + num2;
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}
