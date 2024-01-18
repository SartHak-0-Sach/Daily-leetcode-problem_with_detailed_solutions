#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {
//         long long int prev1 = 1;
//         long long int prev2 = 1;

//         for(int i = 0; i < n; i++){
//             long long int temp = prev1; // iterative approach
//             prev1 = prev1 + prev2;
//             prev2 = temp;

//         }

//         return prev2;
//     }
// };

class Solution {
public:
    int solveUsingMem(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp); // memoization approach
        dp[n] = ans;
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = solveUsingMem(n, dp);
        return ans;
    }
};