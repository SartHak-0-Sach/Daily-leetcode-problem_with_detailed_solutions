#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;

        if (n <= 0)
            return 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i, ++ans)
            dp[i][i] = true;

        for (int i = 0; i < n - 1; ++i)
        {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            ans += (dp[i][i + 1] ? 1 : 0);
        }

        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j)
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                ans += (dp[i][j] ? 1 : 0);
            }

        return ans;
    }
};