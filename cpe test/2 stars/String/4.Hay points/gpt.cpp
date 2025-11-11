#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dictionaryWordCount, descriptionCount;
    cin >> dictionaryWordCount >> descriptionCount;

    unordered_map<string, int> wordValueMap;
    string word;
    int value;

    // 讀取字典
    for (int i = 0; i < dictionaryWordCount; ++i) {
        cin >> word >> value;
        wordValueMap[word] = value;
    }

    string line;
    getline(cin, line); // 吃掉換行

    // 處理每個 job description
    for (int i = 0; i < descriptionCount; ++i) {
        long long totalSalary = 0;

        while (true) {
            getline(cin, line);
            if (line == ".") break; // 遇到句點結束一份描述

            stringstream lineStream(line);
            while (lineStream >> word) {
                if (wordValueMap.count(word))
                    totalSalary += wordValueMap[word];
            }
        }

        cout << totalSalary << "\n";
    }

    return 0;
}
