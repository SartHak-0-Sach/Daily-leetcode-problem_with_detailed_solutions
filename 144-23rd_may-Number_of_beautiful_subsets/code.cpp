#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int prevNum = -k, prev2, prev1 = 1, curr;
            for (auto& [num, f]: fr.second) {
                int skip = prev1;
                int take = ((1 << f) - 1) * (num - prevNum == k ? prev2 : prev1);
                curr = skip + take;
                prev2 = prev1; prev1 = curr;
                prevNum = num;
            }
            result *= curr;
        }
        return result - 1;
    }
};