#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int pathSum)
    {
        if (!node)
            return 0;

        pathSum = pathSum * 10 + node->val;

        if (!node->left && !node->right)
            return pathSum;

        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }
};