#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void viewFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "File does not exist. A new file will be created.\n";
        return;
    }

    cout << "\n--- Current File Content ---\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "-----------------------------\n";
    inFile.close();
}

void editFile(const string& filename) {
    ofstream outFile(filename, ios::app); // append mode
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    cout << "Enter text to append (type ':wq' on a new line to save and exit):\n";
    string line;
    while (true) {
        getline(cin, line);
        if (line == ":wq")
            break;
        outFile << line << endl;
    }

    outFile.close();
}

int main() {
    string filename;
    cout << "Enter filename to edit: ";
    getline(cin, filename);

    viewFile(filename);
    editFile(filename);

    cout << "File saved successfully.\n";
    return 0;
}
