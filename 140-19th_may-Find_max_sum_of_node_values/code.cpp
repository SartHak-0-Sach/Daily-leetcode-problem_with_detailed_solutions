#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n, k;
    long long dp[20000][2];
    long long f(int i, bool c, vector<int>& nums ){
        if (i==n) return (c)?INT_MIN:0;
        if (dp[i][c]!=-1) return dp[i][c];
        long long x=nums[i]; 
        return dp[i][c]=max(x+f(i+1,c, nums), (x^k)+f(i+1,!c, nums));
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        n=nums.size();
        this->k=k;
        fill(&dp[0][0], &dp[0][0]+20000*2, -1);
        return f(0, 0, nums);
    }
};