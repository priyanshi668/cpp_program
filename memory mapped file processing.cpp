#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;

void processFile(const string& filename) {
    // Open the file
    int fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    // Get the size of the file
    off_t fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1) {
        cerr << "Error: Unable to determine file size" << endl;
        close(fd);
        return;
    }

    // Map the file into memory
    char* mappedFile = static_cast<char*>(mmap(nullptr, fileSize, PROT_READ, MAP_PRIVATE, fd, 0));
    if (mappedFile == MAP_FAILED) {
        cerr << "Error: Memory mapping failed" << endl;
        close(fd);
        return;
    }

    // Process the file (in this case, just print the contents)
    cout << "File contents:\n";
    for (off_t i = 0; i < fileSize; ++i) {
        cout << mappedFile[i];
    }
    cout << endl;

    // Unmap the file from memory and close the file descriptor
    if (munmap(mappedFile, fileSize) == -1) {
        cerr << "Error: Failed to unmap memory" << endl;
    }

    close(fd);
}

int main() {
    string filename;
    cout << "Enter the name of the file to process: ";
    getline(cin, filename);

    processFile(filename);

    return 0;
}
