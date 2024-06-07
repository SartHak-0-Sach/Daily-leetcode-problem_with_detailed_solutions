#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n<groupSize || n%groupSize!=0) return false;
        unordered_map<int,int>m;
        for(auto i:hand)m[i]++;
        sort(hand.begin(),hand.end());
        for(auto i:hand){
            if(m[i]==0)continue;
            bool flag=1;
            for(int k=0;k<groupSize;k++){
                if(m[i+k]<=0){
                    flag=0;
                    break;
                }
                else m[i+k]--;
            }
            if(!flag) return false;
            }
        return true;
    }
};