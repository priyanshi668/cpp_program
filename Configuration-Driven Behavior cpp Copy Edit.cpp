#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

// Function to parse configuration file
map<string, string> readConfig(const string& filename) {
    map<string, string> config;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open config file." << endl;
        return config;
    }

    string line;
    while (getline(file, line)) {
        size_t equalPos = line.find('=');
        if (equalPos != string::npos) {
            string key = line.substr(0, equalPos);
            string value = line.substr(equalPos + 1);
            config[key] = value;
        }
    }
    file.close();
    return config;
}

int main() {
    const string configFile = "config.txt";
    auto config = readConfig(configFile);

    // Use settings from the config file
    string username = config["username"];
    string language = config["language"];
    bool verbose = (config["verbose"] == "true");

    if (language == "English") {
        cout << "Hello, " << username << "!" << endl;
    } else if (language == "Spanish") {
        cout << "¡Hola, " << username << "!" << endl;
    } else {
        cout << "Hello (unknown language), " << username << "!" << endl;
    }

    if (verbose) {
        cout << "[Verbose] Username: " << username << endl;
        cout << "[Verbose] Language: " << language << endl;
        cout << "[Verbose] Verbose mode is ON." << endl;
    }

    return 0;
}
