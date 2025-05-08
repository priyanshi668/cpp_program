
#include <iostream>
#include <fstream>
#include <exception>

class FileHandler {
private:
    std::ofstream file;
public:
    FileHandler(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file.");
        }
        std::cout << "File opened successfully.\n";
    }

    void writeToFile(const std::string& data) {
        file << data << std::endl;
        std::cout << "Data written to file.\n";
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed in destructor (finally block).\n";
        }
    }
};

int main() {
    try {
        FileHandler fh("example.txt");
        fh.writeToFile("Hello, this is a test.");

        // Simulate an exception
        throw std::runtime_error("An error occurred while processing.");
    }
    catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    std::cout << "Program continues after exception handling.\n";
    return 0;
}
