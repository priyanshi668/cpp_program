#include <iostream>
#include <string>
using namespace std;

// Class definition for Book
class Book {
private:
    string title;
    string author;
    double price;

public:
    // Constructor to initialize the Book object
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    // Method to display the book details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    int n;

    // Ask the user for the number of books
    cout << "Enter the number of books: ";
    cin >> n;

    // Dynamically allocate an array of Book objects using 'new'
    Book* books = new Book[n];

    // Input book details
    for (int i = 0; i < n; i++) {
        string title, author;
        double price;

        cout << "\nEnter details for Book " << i + 1 << endl;
        cout << "Title: ";
        cin.ignore();  // To ignore any leftover newline character in the input buffer
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Price: ";
        cin >> price;

        // Initialize the Book object
        books[i] = Book(title, author, price);
    }

    // Display the details of all books using the pointer to the array
    cout << "\nBook details:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << " details:" << endl;
        books[i].displayDetails();  // Access each Book object and call displayDetails()
    }

    // Deallocate the memory used for the array of Book objects
    delete[] books;

    return 0;
}
