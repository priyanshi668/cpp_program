#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
              [](unsigned char c) { return tolower(c); });
    return lowerStr;
}

// Helper function to remove punctuation from a word
string removePunctuation(const string& str) {
    string cleanStr;
    for (char c : str) {
        if (!ispunct(c)) {
            cleanStr += c;
        }
    }
    return cleanStr;
}

int main() {
    string filename, targetWord;
    cout << "Enter filename: ";
    getline(cin, filename);

    cout << "Enter word to search: ";
    cin >> targetWord;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file.\n";
        return 1;
    }

    string word;
    int count = 0;
    targetWord = toLower(targetWord);

    while (file >> word) {
        word = toLower(removePunctuation(word));
        if (word == targetWord) {
            ++count;
        }
    }

    file.close();

    cout << "The word '" << targetWord << "' occurred " << count << " times in the file.\n";
    return 0;
}
