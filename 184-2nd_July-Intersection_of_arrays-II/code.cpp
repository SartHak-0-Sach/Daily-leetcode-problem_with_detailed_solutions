#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> box;
        for (int num : nums1)
            box[num]++;
        for (int i = 0; i < nums2.size(); ++i) {
            if (box[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                box[nums2[i]]--;
            } else {
                continue;
            }
        }
        return res;
    }
};