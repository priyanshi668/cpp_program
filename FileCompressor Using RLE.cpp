#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileCompressor {
public:
    // Compress using simple Run-Length Encoding
    void compress(const string& inputFile, const string& outputFile) {
        ifstream in(inputFile);
        ofstream out(outputFile);

        if (!in || !out) {
            cerr << "File error!" << endl;
            return;
        }

        char currentChar, prevChar = '\0';
        int count = 0;

        while (in.get(currentChar)) {
            if (currentChar == prevChar) {
                count++;
            } else {
                if (count > 0) {
                    out << count << prevChar;
                }
                count = 1;
                prevChar = currentChar;
            }
        }

        // Write remaining characters
        if (count > 0) {
            out << count << prevChar;
        }

        in.close();
        out.close();
        cout << "Compression complete." << endl;
    }

    // Decompress simple Run-Length Encoded file
    void decompress(const string& inputFile, const string& outputFile) {
        ifstream in(inputFile);
        ofstream out(outputFile);

        if (!in || !out) {
            cerr << "File error!" << endl;
            return;
        }

        char ch;
        string countStr;

        while (in >> ws && isdigit(in.peek())) {
            countStr = "";
            while (isdigit(in.peek())) {
                in.get(ch);
                countStr += ch;
            }

            int count = stoi(countStr);
            in.get(ch); // get the character

            for (int i = 0; i < count; ++i) {
                out.put(ch);
            }
        }

        in.close();
        out.close();
        cout << "Decompression complete." << endl;
    }
};

// Example usage
int main() {
    FileCompressor fc;

    string input = "original.txt";
    string compressed = "compressed.rle";
    string decompressed = "decompressed.txt";

    // Create test input file
    ofstream test(input);
    test << "aaaabbbccdddddd";
    test.close();

    fc.compress(input, compressed);
    fc.decompress(compressed, decompressed);

    return 0;
}
