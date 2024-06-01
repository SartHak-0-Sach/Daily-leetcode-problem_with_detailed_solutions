#include <iostream>
#include <functional>
#include <iterator>
#include <climits>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    static vector<int> singleNumber(vector<int> &nums)
    {
        int XOR = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        // XOR=a^b

        // Find least bit=1 for XOR
        // same as
        // int i=__builtin_ffs(XOR)-1;
        int i = 0;
        while (((XOR >> i) & 1) == 0)
            i++;
        // i-th bit=1

        int A = 0, B = 0;
        for (int x : nums)
        {
            if (((x >> i) & 1) == 0)
                A ^= x;
            else
                B ^= x;
        }
        //    A^=XOR, B^=XOR;
        return {A, B};
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();