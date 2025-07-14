#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

// function to read C++ keywords from a file and store them in a set
set<string> readCppKeywords() {
    ifstream file("cpp_keywords.txt");
    set<string> keywords;
    string word;

    while (file >> word) {
        keywords.insert(word);
    }

    return keywords;
}

int main() {

    cout << "Enter the name of the C program file (e.g., user_program.c): "; 
    string filename;
    cin >> filename;
    cin.ignore(); // to ignore the newline character after filename input

    ofstream outfile(filename);
    string line;
    cout << "Enter your C program (type 'END;' on a new line to finish)" << endl;

    while (getline(cin, line)) {
        if (line == "END;") break;
        outfile << line << endl;
    }

    outfile.close();

    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file!" << endl;
        return 1;
    }
    set<string> cppKeywords = readCppKeywords();
    string word;
    map<string, int> keywordFrequency;
    while (infile >> word) {
        // Convert to lowercase for case-insensitive comparison
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (cppKeywords.find(word) != cppKeywords.end()) {
            keywordFrequency[word]++;
        }
    }

    

    cout << "Lexer Analysis Complete" << endl;
    cout << "Keyword Frequencies:";
    for (const auto& kw : keywordFrequency) {
        cout << kw.first << ": " << kw.second << endl;
    }

    return 0;
}