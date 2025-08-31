#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> sentences;
    string line;
    int maxLength = 0;

    // Read input
    while (getline(cin, line)&& !line.empty()) {
        sentences.push_back(line);
        if (line.length() > maxLength)
            maxLength = line.length();
    }

    // Pad sentences with spaces
    for (auto &s : sentences) {
        while (s.length() < maxLength)
            s += ' ';
    }

    // Rotate 90 degrees clockwise
    for (int col = 0; col < maxLength; col++) {
        for (int row = sentences.size() - 1; row >= 0; row--) {
            cout << sentences[row][col];
        }
        cout << endl;
    }

    return 0;
}
