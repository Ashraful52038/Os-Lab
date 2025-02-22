#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    outFile << "Hello, World!" << endl;
    outFile << "File Manipulation in C++." << endl;
    outFile.close();

    // Reading from a file
    ifstream inFile("example.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
