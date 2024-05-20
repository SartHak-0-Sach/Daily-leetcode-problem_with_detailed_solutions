#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    map<char, vector<int>> mp;
    string s, key;
    int n,m;
    int dp[105][105];

    int f(int i,int j){

        if(j==key.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]==key[j]){
            return 1 + f(i, j+1);
        }

        int ans = 1e9;
        vector<int> allIdx = mp[key[j]];

        for(int ind : allIdx){
            int minDist = min(abs(i-ind), n - abs(i-ind));
            ans = min(ans, minDist + f(ind, j));
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {

        n = ring.size();
        m = key.size();
        this->s = ring;
        this->key=key;
        
        for(int i=0; i<ring.size(); i++){
            mp[ring[i]].push_back(i);
        }

        memset(dp, -1, sizeof(dp));
        return f(0, 0);        
    }
};