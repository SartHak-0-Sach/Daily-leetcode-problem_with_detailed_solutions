#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
                candidate = num;

            if (num == candidate)
                count++;

            else
                count--;
        }
        return candidate;
    }
};