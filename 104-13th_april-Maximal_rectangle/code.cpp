#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0); // Include an extra element for easier calculation
        int maxArea = 0;

        for (const auto &row : matrix)
        {
            for (int i = 0; i < cols; i++)
            {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            // Calculate max area using stack-based method
            stack<int> stk;
            for (int i = 0; i < heights.size(); i++)
            {
                while (!stk.empty() && heights[i] < heights[stk.top()])
                {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                stk.push(i);
            }
        }

        return maxArea;
    }
};