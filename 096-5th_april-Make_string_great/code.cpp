#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        int i = 1; // Start from index 1 instead of 0
        while (i < s.length())
        {
            if (abs(s[i] - s[i - 1]) == 32)
            {                      // Compare characters, not their ASCII values
                s.erase(i - 1, 2); // Erase the pair of characters
                if (i > 1)         // Update i based on the previous characters if possible
                    i--;
            }
            else
            {
                i++; // Move to the next character
            }
        }
        return s;
    }
};