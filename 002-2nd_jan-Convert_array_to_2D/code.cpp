#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> visited(n , 0);
        for (int i=0 ; i<n ; i++)
        {
            visited[nums[i]-1]++;
        }

        int largest = 0;

        for (int i = 0; i < n; i++)
        {
            if(visited[i]>largest)
            {
                largest = visited[i];
            }
        }

        vector<vector<int>> ans;
        vector<int> arr;

        for (int i = 0; i < largest; i++)
        {
            arr.clear();
            for (int j = 0; j < n; j++)
            {
                if(visited[j]>0)
                {
                    arr.push_back(j+1);
                    visited[j]--;
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};

// This code can further be optimised a little bit by implementing the same logic but by using unordered map