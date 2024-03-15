#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answers;
        int product = 1;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                flag++;
            else
                product *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 && flag - 1 == 0)
                answers.push_back(product);
            else if (flag >= 1)
                answers.push_back(0);
            else
                answers.push_back(product / nums[i]);
        }
        return answers;
    }
};