#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool threeConsecutiveOdds(vector<int> &arr)
    {
        int len = 0;
        for (int x : arr)
        {
            len = (x & 1) ? len + 1 : 0;
            if (len == 3)
                return 1;
        }
        return 0;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();