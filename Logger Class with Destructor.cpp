#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    ofstream logFile;

public:
    // Constructor that opens the log file
    Logger(const string &filename) {
        logFile.open(filename, ios::app);  // Open in append mode to keep existing logs
        if (logFile.is_open()) {
            logFile << "Logger initialized." << endl;
            cout << "Logger initialized and logging started." << endl;
        } else {
            cout << "Error opening log file!" << endl;
        }
    }

    // Method to log a message
    void logMessage(const string &message) {
        if (logFile.is_open()) {
            logFile << message << endl;
        }
    }

    // Destructor that logs a message when the object is destroyed
    ~Logger() {
        if (logFile.is_open()) {
            logFile << "Logger closed." << endl;  // Log message when object is destroyed
            logFile.close();  // Close the log file
            cout << "Logger closed and file saved." << endl;
        }
    }
};

int main() {
    // Create a Logger object that will write to "log.txt"
    Logger logger("log.txt");

    // Log some messages
    logger.logMessage("This is a log message.");
    logger.logMessage("Logging another message.");

    // Destructor will be called automatically when the object goes out of scope
    return 0;
}
