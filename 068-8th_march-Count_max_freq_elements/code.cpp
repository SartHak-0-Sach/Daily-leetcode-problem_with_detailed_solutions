#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0}, maxF=0;
        for (int x: nums){
            freq[x]++;
            maxF=max(maxF, freq[x]);
        }
        int ans=0;
        for (int f: freq){
            if (f==maxF)
                ans+=f;
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();