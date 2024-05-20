#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    // This function finds the 2 smallest numbers in a given row
    array<int, 2> findmin2(vector<int> &row)
    {
        int x0 = INT_MAX, x1 = INT_MAX; // Initialize two variables with maximum integer value
        for (int x : row)
        { // For each element in the row
            if (x < x0)
            {                         // If the element is smaller than x0
                x1 = exchange(x0, x); // Exchange the values of x0 and x, and assign the old value of x0 to x1
                //    x1=x0;
                //    x0=x;
            }
            else if (x < x1)
                x1 = x; // If the element is not smaller than x0 but smaller than x1, assign it to x1
        }
        return {x0, x1}; // Return the two smallest numbers
    }

    // main function
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(); // Get the size of the grid

        for (int i = 1; i < n; i++)
        { // main nested loop
            auto min2 = findmin2(grid[i - 1]);
            for (int j = 0; j < n; j++)
            {
                if (grid[i - 1][j] == min2[0])
                    grid[i][j] += min2[1];
                else
                    grid[i][j] += min2[0];
            }
        }

        // Return the smallest element in the last row of the grid
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};