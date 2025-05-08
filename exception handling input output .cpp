#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

int main() {
    string filename;
    cout << "Enter the filename to read from: ";
    cin >> filename;

    ifstream file;

    try {
        // Set exception mask for the ifstream object
        file.exceptions(ifstream::failbit | ifstream::badbit);

        file.open(filename);

        string line;
        cout << "File contents:\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    } catch (const ifstream::failure& e) {
        cerr << "File I/O error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred while working with the file." << endl;
    }

    return 0;
}
