#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string sourceFileName = "source.txt";
    string destinationFileName = "destination.txt";

    ifstream sourceFile(sourceFileName);  // Open source file for reading
    ofstream destinationFile(destinationFileName);  // Open destination file for writing

    // Check if files opened successfully
    if (!sourceFile) {
        cerr << "Error: Could not open source file." << endl;
        return 1;
    }
    if (!destinationFile) {
        cerr << "Error: Could not open/create destination file." << endl;
        return 1;
    }

    string line;
    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }

    sourceFile.close();
    destinationFile.close();

    cout << "File copied successfully from '" << sourceFileName 
         << "' to '" << destinationFileName << "'." << endl;

    return 0;
}
