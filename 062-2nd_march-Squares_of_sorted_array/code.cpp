#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    int getMax(vector<int> &arr)
    {
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++) // radix sort code
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    void countSort(vector<int> &arr, int exp)
    {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = output[i];
        }
    }

    void radixSort(vector<int> &arr)
    {
        int max = getMax(arr);

        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            countSort(arr, exp);
        }
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        radixSort(nums);
        return nums;
    }
};

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    { // 2 pointer approach code
        int n = nums.size();
        int s = 0, e = n - 1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(nums[s]) >= abs(nums[e]))
            {
                ans[i] = nums[s] * nums[s];
                s++;
            }
            else
            {
                ans[i] = nums[e] * nums[e];
                e--;
            }
        }
        return ans;
    }
};