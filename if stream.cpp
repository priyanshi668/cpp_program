#include <iostream>   // For cin, cout
#include <fstream>    // For ifstream
#include <vector>     // For vector

using namespace std;

int main() {
    // Create an input file stream (ifstream) to read from the file
    ifstream inFile("numbers.txt");

    // Check if the file was opened successfully
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    int num;
    vector<int> numbers;

    // Read integers from the file and store them in a vector
    while (inFile >> num) {
        numbers.push_back(num);
    }

    // Display the integers read from the file
    cout << "The integers read from the file are:\n";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // Close the input file stream
    inFile.close();

    return 0;
}
