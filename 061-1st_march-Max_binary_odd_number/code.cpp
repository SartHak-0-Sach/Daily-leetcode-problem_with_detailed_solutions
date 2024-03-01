#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int ones = count(s.begin(), s.end(), '1');
        int sz = s.size();

        string res = "1";

        int nonOnes = sz - ones;
        ones--;

        while (nonOnes-- > 0)
        {
            res += "0";
        }
        while (ones-- > 0)
        {
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};