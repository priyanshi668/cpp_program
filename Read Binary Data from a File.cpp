#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* filename = "data.bin";

    // Open the file in binary mode
    ifstream inFile(filename, ios::binary);

    // Check if the file was successfully opened
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    int number;
    double value;

    // Read binary data
    inFile.read(reinterpret_cast<char*>(&number), sizeof(number));
    inFile.read(reinterpret_cast<char*>(&value), sizeof(value));

    inFile.close();

    // Display the data read
    cout << "Integer read from file: " << number << endl;
    cout << "Double read from file: " << value << endl;

    return 0;
}
