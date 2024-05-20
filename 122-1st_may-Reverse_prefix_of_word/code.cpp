#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int a=word.find(ch)+1;
        reverse(word.begin(),word.begin()+a);
        return word;
    }
};