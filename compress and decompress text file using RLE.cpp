#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Compress the content using RLE
string compress(const string& text) {
    string result;
    int len = text.length();

    for (int i = 0; i < len; ++i) {
        result += text[i];
        int count = 1;
        while (i + 1 < len && text[i] == text[i + 1]) {
            ++count;
            ++i;
        }
        result += to_string(count);
    }

    return result;
}

// Decompress RLE content
string decompress(const string& text) {
    string result;
    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        string countStr;

        while (i + 1 < text.length() && isdigit(text[i + 1])) {
            countStr += text[++i];
        }

        int count = stoi(countStr);
        result.append(count, ch);
    }
    return result;
}

int main() {
    string choice;
    cout << "Do you want to (c)ompress or (d)ecompress a file? ";
    cin >> choice;
    cin.ignore(); // to consume leftover newline

    string inputFile, outputFile;
    cout << "Enter input filename: ";
    getline(cin, inputFile);
    cout << "Enter output filename: ";
    getline(cin, outputFile);

    ifstream in(inputFile);
    if (!in) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    stringstream buffer;
    buffer << in.rdbuf();
    string content = buffer.str();
    in.close();

    ofstream out(outputFile);
    if (!out) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    if (choice == "c") {
        out << compress(content);
        cout << "File compressed successfully.\n";
    } else if (choice == "d") {
        out << decompress(content);
        cout << "File decompressed successfully.\n";
    } else {
        cout << "Invalid option.\n";
    }

    out.close();
    return 0;
}
