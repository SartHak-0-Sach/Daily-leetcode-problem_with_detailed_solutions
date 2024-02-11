#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int dp[2][70][70] = {0};

        // base case for the last row
        for (int c0 = 0; c0 < col; c0++)
            for (int c1 = 0; c1 < col; c1++)
            {
                dp[(row - 1) & 1][c0][c1] = (c0 != c1) ? grid[row - 1][c0] + grid[row - 1][c1] : grid[row - 1][c0];
            }
        // DP from r=row-2 to 0
        for (int r = row - 2; r >= 0; r--)
        {
            for (int c0 = 0; c0 < col; c0++)
                for (int c1 = 0; c1 < col; c1++)
                {
                    int cherry = (c0 != c1) ? grid[r][c0] + grid[r][c1] : grid[r][c0];
                    int next = 0;

                    for (int d0 : {c0 - 1, c0, c0 + 1})
                        for (int d1 : {c1 - 1, c1, c1 + 1})
                        {
                            if (d0 < 0 || d0 >= col || d1 < 0 || d1 >= col)
                                continue;
                            next = max(next, dp[(r + 1) & 1][d0][d1]);
                        }
                    dp[r & 1][c0][c1] = next + cherry;
                }
        }

        return dp[0][0][col - 1];
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();