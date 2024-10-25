class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = 26;
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            grid[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++)
        {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            grid[from][to] = min(grid[from][to], cost[i]);
        }

        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][via] != INT_MAX && grid[via][j] != INT_MAX)
                    {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (source[i] != target[i])
            {
                int cost = grid[source[i] - 'a'][target[i] - 'a'];
                if (cost == INT_MAX)
                    return -1;
                ans += cost;
            }
        }
        return ans;
    }
};