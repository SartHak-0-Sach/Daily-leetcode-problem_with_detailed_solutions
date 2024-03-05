#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        ios_base::sync_with_stdio(0);
        int first = 0;
        int last = s.length() - 1;
        char his = 'd';
        while (first < last)
        {
            char temp = s[first];
            if (s[first] == s[last])
            {
                while ((first != last) && (temp == s[++first]))
                {
                }
                while ((first != last) && (temp == s[--last]))
                {
                }
                his = temp;
            }
            else
            {
                break;
            }
        };

        if (first < last)
        {
            return last - first + 1;
        }
        else if ((first == last) && (s[first] != his))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};