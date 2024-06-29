#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:  

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        for(int i=0;i<roads.size();i++){
            int f,s;
            f=roads[i][0];
            s=roads[i][1];

            graph[f].insert(s);
            graph[s].insert(f);
        }

        vector<pair<int,int>> imp(n);

        for(int i=0;i<n;i++){
            imp[i].first=graph[i].size();
            imp[i].second=i;
        } 
        sort(imp.begin(),imp.end());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[imp[i].second]=i+1;
        }

        long long ans=0;
        for(int i=0;i<roads.size();i++){
            ans+=mp[roads[i][0]];
            ans+=mp[roads[i][1]];
        }
        return ans;        
    }
};