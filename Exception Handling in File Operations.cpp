#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

void readFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    cout << "\n--- File Content ---\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void writeFile(const string& filename, const string& content) {
    ofstream file(filename, ios::app); // Append mode

    if (!file) {
        throw runtime_error("Unable to write to file: " + filename);
    }

    file << content << endl;
    file.close();
}

int main() {
    string filename = "example.txt";
    string content;

    try {
        cout << "Enter text to write to '" << filename << "': ";
        getline(cin, content);
        writeFile(filename, content);

        cout << "Writing complete.\n";
        readFile(filename);
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
