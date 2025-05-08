#include <iostream>
#include <string>
using namespace std;

// Library class
class Library {
private:
    string bookTitle;  // Private member
    int bookID;        // Private member

protected:
    string libraryName; // Protected member

public:
    // Constructor to initialize all members
    Library(string title, int id, string name) 
        : bookTitle(title), bookID(id), libraryName(name) {}

    // Public method to access and display book details
    void displayBookDetails() const {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Library Name: " << libraryName << endl;
    }

    // Public method to demonstrate accessing private members via getter functions
    void setBookDetails(string title, int id) {
        bookTitle = title;
        bookID = id;
    }

    // Public method to access protected member
    void displayLibraryName() const {
        cout << "Library Name: " << libraryName << endl;
    }
};

// Derived class to access protected member and show visibility of inherited members
class SpecialLibrary : public Library {
public:
    // Constructor to initialize base class members and new member
    SpecialLibrary(string title, int id, string name)
        : Library(title, id, name) {}

    // Public method to demonstrate accessing protected members of the base class
    void displaySpecialLibraryInfo() {
        cout << "This library's name is: " << libraryName << endl;
    }
};

int main() {
    // Create object of Library class
    Library lib("C++ Programming", 101, "Central Library");

    // Access public method to display book and library details
    lib.displayBookDetails();
    lib.displayLibraryName();

    // Modify book details using public method
    lib.setBookDetails("Advanced C++", 102);
    lib.displayBookDetails();

    // Create object of SpecialLibrary class
    SpecialLibrary specLib("Data Structures", 103, "Special Library");

    // Access public and inherited protected member in derived class
    specLib.displaySpecialLibraryInfo();

    // The following line will generate a compile-time error because bookTitle is private in the base class
    // cout << lib.bookTitle << endl;

    // The following line will also generate a compile-time error because bookID is private in the base class
    // cout << lib.bookID << endl;

    return 0;
}
