#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const char* filename = "numbers.dat";

    // --- Step 1: Write integers to a binary file ---
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "Error opening file for writing." << endl;
            return 1;
        }

        int numbers[] = {10, 20, 30, 40, 50};
        outFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        outFile.close();
        cout << "Binary file written with integers.\n";
    }

    // --- Step 2: Read and display contents in reverse order ---
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }

        // Move to the end to determine file size
        inFile.seekg(0, ios::end);
        streampos fileSize = inFile.tellg();
        int count = fileSize / sizeof(int);

        cout << "Contents of binary file in reverse order:\n";

        // Read each integer in reverse
        for (int i = count - 1; i >= 0; --i) {
            inFile.seekg(i * sizeof(int), ios::beg);
            int value;
            inFile.read(reinterpret_cast<char*>(&value), sizeof(int));
            cout << value << " ";
        }

        inFile.close();
    }

    return 0;
}
