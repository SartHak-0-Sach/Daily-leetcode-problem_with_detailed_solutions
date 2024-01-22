#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int s = nums.size();
        int visited[s+1];
        // int visited[s]={0};

        for(int i = 0; i<=s; i++)
        {
            visited[i]=0;
        }

        for(int i = 0; i < s; i++)
        {
            visited[nums[i]] = visited[nums[i]] - 1;
        }
        
        for(int i = 1; i < s+1; i++)
        {
            if(visited[i]==-2)
            {
                ans.push_back(i);
            }
        }

        for(int i = 1; i < s+1; i++)
        {
            if(visited[i]==0)
            {
                ans.push_back(i);
            }
        }

        return ans;

    }
};