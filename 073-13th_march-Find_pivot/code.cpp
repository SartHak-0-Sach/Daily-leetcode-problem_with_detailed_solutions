#include <iostream>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int total_sum = n * (1 + n) / 2, cur_sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cur_sum += i;
            if ((total_sum - cur_sum + i) == cur_sum)
                return i;
        }
        return -1;
    }
};