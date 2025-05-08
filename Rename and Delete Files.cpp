#include <iostream>
#include <cstdio>  // For rename() and remove()

using namespace std;

int main() {
    const char* oldFilename = "old_file.txt";
    const char* newFilename = "new_file.txt";

    // Rename the file
    if (rename(oldFilename, newFilename) == 0) {
        cout << "File renamed successfully from " << oldFilename << " to " << newFilename << endl;
    } else {
        cerr << "Error: Unable to rename the file." << endl;
    }

    // Delete the renamed file
    if (remove(newFilename) == 0) {
        cout << "File " << newFilename << " deleted successfully." << endl;
    } else {
        cerr << "Error: Unable to delete the file." << endl;
    }

    return 0;
}
