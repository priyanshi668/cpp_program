#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string input;
    unordered_map<char, int> frequency;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, input);

    // Count the frequency of each character
    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        // Ignore spaces or non-alphabetic characters if needed
        if (ch != ' ') {
            frequency[ch]++;
        }
    }

    // Output the frequencies of characters
    cout << "Character frequencies in the string: " << endl;
    for (const auto& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
