#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // We will be using depth first search.
    // If we reach the depth we will add the node and return the new node.
    TreeNode *helper(TreeNode *root, int depth, int d, int val, bool left, bool right)
    {
        if (d == depth)
        {
            TreeNode *node = new TreeNode(val);
            if (left)
            {
                node->left = root;
            }
            else
            {
                node->right = root;
            }
            return node;
        }
        if (root == NULL)
            return NULL;
        root->left = helper(root->left, depth, d + 1, val, true, false);

        root->right = helper(root->right, depth, d + 1, val, false, true);

        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        return helper(root, depth, 1, val, true, false);
    }
};