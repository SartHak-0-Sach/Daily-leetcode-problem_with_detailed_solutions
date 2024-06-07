#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());

    istringstream iss(sentence);
    string word;
    string result;

    while (iss >> word) {
        string prefix;
        for (int i = 1; i <= word.size(); ++i) {
            prefix = word.substr(0, i);
            if (rootSet.find(prefix) != rootSet.end()) {
                break;
            }
        }
        result += prefix + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
    }
};