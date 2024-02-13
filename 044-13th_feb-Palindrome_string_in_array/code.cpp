#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool check(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] == s[j])
                i++, j--;
            else
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (check(words[i]))
                return words[i];
        }
        return "";
    }
};