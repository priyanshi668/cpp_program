#include <iostream>
#include <string>
using namespace std;

// Base class Media
class Media {
public:
    // Virtual function to display media info
    virtual void displayInfo() const {
        cout << "This is a media item." << endl;
    }

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Media() {}
};

// Derived class Book
class Book : public Media {
private:
    string title;
    string author;

public:
    // Constructor to initialize book details
    Book(const string& t, const string& a) : title(t), author(a) {}

    // Overridden displayInfo function for Book
    void displayInfo() const override {
        cout << "Book Title: " << title << ", Author: " << author << endl;
    }
};

// Derived class DVD
class DVD : public Media {
private:
    string title;
    int duration; // in minutes

public:
    // Constructor to initialize DVD details
    DVD(const string& t, int d) : title(t), duration(d) {}

    // Overridden displayInfo function for DVD
    void displayInfo() const override {
        cout << "DVD Title: " << title << ", Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    // Creating base class pointers to derived class objects
    Media* media1 = new Book("1984", "George Orwell");
    Media* media2 = new DVD("Inception", 148);

    // Demonstrating polymorphism by calling the overridden displayInfo function
    media1->displayInfo(); // Will call Book's displayInfo()
    media2->displayInfo(); // Will call DVD's displayInfo()

    // Deallocate memory
    delete media1;
    delete media2;

    return 0;
}
