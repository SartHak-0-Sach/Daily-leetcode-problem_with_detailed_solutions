class Solution
{
public:
    static vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> minPos(m, -1);
        for (int i = 0; i < m; i++)
        {
            int p = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            minPos[i] = p;
        }
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int p = minPos[i], x = matrix[i][p];
            bool lucky = 1;
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][p] > x)
                {
                    lucky = 0;
                    break;
                }
            }
            if (lucky)
                ans.push_back(x);
        }
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();