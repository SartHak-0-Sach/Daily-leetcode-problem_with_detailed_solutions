#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>mp1;
        for(auto it : nums1)
        {
            mp1[it]=true;
        }
        for(auto it : nums2)
        {
            if(mp1[it]==true)
            {
                return it;
            }
        }
        return -1;
     }
};