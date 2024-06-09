#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map = {{0, 1}};
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            if(prefix_map.find(sum) != prefix_map.end()) {
                ans += prefix_map[sum];
                prefix_map[sum]++;
            } else {
                prefix_map[sum] = 1;
            }
        }
        return ans;
    }
};