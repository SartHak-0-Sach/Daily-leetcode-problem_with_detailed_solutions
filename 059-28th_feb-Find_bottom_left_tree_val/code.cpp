#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int leftmost_value;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            leftmost_value = node->val;

            if (node->right)
            {
                q.push(node->right);
            }
            if (node->left)
            {
                q.push(node->left);
            }
        }

        return leftmost_value;
    }
};