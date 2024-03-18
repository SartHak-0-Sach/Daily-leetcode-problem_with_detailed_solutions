#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> merged;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            merged.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        merged.push_back(newInterval);

        while (i < intervals.size())
        {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};