#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* filename = "data.bin";

    ofstream outFile(filename, ios::binary);  // Open file in binary write mode

    // Check if file opened successfully
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    int number = 42;
    double value = 3.14159;

    // Write the data to the file in binary format
    outFile.write(reinterpret_cast<char*>(&number), sizeof(number));
    outFile.write(reinterpret_cast<char*>(&value), sizeof(value));

    outFile.close();  // Close the file

    cout << "Binary data written to " << filename << " successfully." << endl;

    return 0;
}
