#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        bitset<1001> A=0, B=0;
        for (int x: nums1) A[x]=1;
        for (int x: nums2) B[x]=1;
        vector<int> ans;
        ans.reserve(1001);
        for (int x=0; x<=1000; x++)
            if (A[x] && B[x]) ans.push_back(x);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();