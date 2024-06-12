#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3]={0};
        for(int x: nums)
            freq[x]++;
        int n=nums.size(), count=0;
        for(int x=0; x<3; x++){
            fill(nums.begin()+count, nums.begin()+count+freq[x], x);
            count+=freq[x];
        }
        
    }
};