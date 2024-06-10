#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <cstring>

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<char> sorted(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int n=heights.size(), ans=0;
        for(int i=0; i<n; i++)
            ans+=(heights[i]!=sorted[i]);
        return ans;      
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();