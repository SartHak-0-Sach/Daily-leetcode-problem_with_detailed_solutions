#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    unordered_map<int, vector<int>> graph;
    int amountOfTime(TreeNode *root, int start)
    {
        constructGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutesPassed = -1;

        while (!q.empty())
        {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize)
            {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode])
                {
                    if (!visited.count(adjacentNode))
                    {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode *root)
    {
        if (!root)
            return;

        if (root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};