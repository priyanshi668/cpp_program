#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    double price;

public:
    // Parameterized constructor to initialize book details
    Book(string t, string a, int y, double p) {
        title = t;
        author = a;
        year = y;
        price = p;
    }

    // Method to display book details
    void displayDetails() {
        cout << "Book Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    // Creating a Book object using parameterized constructor
    Book book1("The Catcher in the Rye", "J.D. Salinger", 1951, 10.99);

    // Displaying the book details
    book1.displayDetails();

    return 0;
}
