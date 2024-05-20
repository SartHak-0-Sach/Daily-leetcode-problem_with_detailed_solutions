#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& v, int k) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<=30;i++) {
            int b=0;
            for(int j=0;j<n;j++) {
                if(((v[j]>>i)&1)==1)
                    b=b^1;
            }
            if(((k>>i)&1)!=b)
                ans++;
        }
        return ans;
    }
};