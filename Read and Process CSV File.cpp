#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Split a CSV line into fields
vector<string> splitCSVLine(const string& line) {
    vector<string> fields;
    stringstream ss(line);
    string field;

    while (getline(ss, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}

int main() {
    ifstream file("data.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    int rowNum = 0;
    while (getline(file, line)) {
        vector<string> fields = splitCSVLine(line);

        cout << "Row " << rowNum++ << ": ";
        for (const auto& field : fields) {
            cout << "[" << field << "] ";
        }
        cout << endl;
    }

    file.close();
    return 0;
}
