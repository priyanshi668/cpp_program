#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize the distance in feet and inches
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        normalize();  // Normalize the inches (if inches >= 12, convert to feet)
    }

    // Friend function to add two distances
    friend Distance addDistances(const Distance &d1, const Distance &d2);

    // Method to display the distance in feet and inches
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

private:
    // Normalize the inches: if inches >= 12, convert to feet
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }
};

// Friend function to add two distances
Distance addDistances(const Distance &d1, const Distance &d2) {
    int totalFeet = d1.feet + d2.feet;
    int totalInches = d1.inches + d2.inches;

    // Create a new Distance object with the sum of the distances
    Distance result(totalFeet, totalInches);
    return result;
}

int main() {
    // Create two Distance objects
    Distance d1(5, 8);  // 5 feet 8 inches
    Distance d2(3, 10); // 3 feet 10 inches

    // Display the original distances
    cout << "Distance 1: ";
    d1.display();
    cout << "Distance 2: ";
    d2.display();

    // Add the two distances using the friend function
    Distance sum = addDistances(d1, d2);

    // Display the result
    cout << "Sum of distances: ";
    sum.display();

    return 0;
}
