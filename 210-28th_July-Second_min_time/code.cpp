class Solution
{
public:
    using int2 = pair<int, int>;

    inline static int wtime(int step, int time, int change)
    {
        int ans = 0;
        for (int i = 0; i < step; i++)
        {
            int gr = ans / change;
            if (gr & 1) // If it's a red light
                ans = (gr + 1) * change;
            ans += time;
        }
        return ans;
    }

    static int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges)
        {
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        vector<int> dist(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        queue<int2> q; // {node, distance}
        q.emplace(1, 0);
        dist[1] = 0;

        while (!q.empty())
        {
            auto [x, d] = q.front();
            q.pop();
            for (int y : adj[x])
            {
                int newD = d + 1;
                if (newD < dist[y])
                {
                    dist2[y] = dist[y];
                    dist[y] = newD;
                    q.emplace(y, newD);
                }
                else if (newD > dist[y] && newD < dist2[y])
                {
                    dist2[y] = newD;
                    q.emplace(y, newD);
                }
            }
        }

        int steps = dist2[n];
        if (steps == INT_MAX)
            return -1;
        return wtime(steps, time, change);
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();