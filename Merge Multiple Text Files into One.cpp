#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void mergeFiles(const vector<string>& inputFiles, const string& outputFile) {
    ofstream out(outputFile);
    if (!out) {
        cerr << "Error opening output file: " << outputFile << endl;
        return;
    }

    for (const string& file : inputFiles) {
        ifstream in(file);
        if (!in) {
            cerr << "Warning: Could not open input file: " << file << ". Skipping.\n";
            continue;
        }

        out << "\n--- Begin File: " << file << " ---\n";
        string line;
        while (getline(in, line)) {
            out << line << '\n';
        }
        out << "--- End File: " << file << " ---\n";

        in.close();
    }

    out.close();
    cout << "Files merged into " << outputFile << " successfully.\n";
}

int main() {
    int n;
    cout << "Enter the number of input files to merge: ";
    cin >> n;
    cin.ignore(); // to clear newline from input buffer

    vector<string> inputFiles(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter name of input file " << (i + 1) << ": ";
        getline(cin, inputFiles[i]);
    }

    string outputFile;
    cout << "Enter name of output file: ";
    getline(cin, outputFile);

    mergeFiles(inputFiles, outputFile);

    return 0;
}
