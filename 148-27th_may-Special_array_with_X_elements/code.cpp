#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n;
        sort(nums.begin(), nums.end());
        while (l <= r){
            int mid = (l + r) / 2;
            int size = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int count = n - size;
            if (count == mid)
                return mid;
            else if (count > mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};