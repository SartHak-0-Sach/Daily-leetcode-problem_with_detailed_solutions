#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    using info = pair<TreeNode *, int>;
    void print(auto &c)
    {
        for (auto node : c)
            cout << node->val << ", ";
        cout << endl;
    }
    bool isLess(auto &q, int qz)
    {
        for (int i = 1; i < qz; i++)
            if (q[i - 1]->val >= q[i]->val)
                return 0;
        return 1;
    }
    bool isGreater(auto &q, int qz)
    {
        for (int i = 1; i < qz; i++)
            if (q[i - 1]->val <= q[i]->val)
                return 0;
        return 1;
    }
    bool isEvenOddTree(TreeNode *root)
    {
        int level = -1;
        deque<TreeNode *> q;
        q.push_back(root);
        while (!q.empty())
        {
            level++;
            int qz = q.size();
            bool isOdd = level & 1;
            //    print(q);
            if ((isOdd && !isGreater(q, qz)) || (!isOdd && !isLess(q, qz)))
                return 0;
            for (int i = 0; i < qz; i++)
            {
                auto node = q.front();
                q.pop_front();
                if ((node->val & 1) == isOdd)
                    return 0;
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
        }
        return 1;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();