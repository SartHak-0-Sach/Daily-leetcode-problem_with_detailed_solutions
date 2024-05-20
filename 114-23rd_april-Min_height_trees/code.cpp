#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};        // edge case
        vector<int> deg(n, 0); // degree
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++;
            deg[w]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        int left = n;
        while (!q.empty())
        {
            int qz = q.size();
            left -= qz; // how many left
            for (int i = 0; i < qz; i++)
            {
                int v = q.front();
                q.pop();
                if (left == 0) // centers are found
                    ans.push_back(v);
                //    cout << v <<": left="<<left<< endl;
                for (int w : adj[v])
                {
                    if (--deg[w] == 1) // remove edge connecting to v
                        q.push(w);
                }
            }
        }
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();