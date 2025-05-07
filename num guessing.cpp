#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int guess, number, attempts = 0;

    // Seed the random number generator
    srand(time(0));
    number = rand() % 100 + 1;  // Random number between 1 and 100

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << endl;

    // Keep prompting the user to guess until they get it right
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the guess is correct
        attempts++;

        if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << number << " in " << attempts << " attempts." << endl;
            break;  // Exit the loop when the guess is correct
        }
    }

    return 0;
}
