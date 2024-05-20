#include <iostream>
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

class Solution
{
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == NULL)
            return NULL;
        TreeNode *left = removeLeafNodes(root->left, target);
        TreeNode *right = removeLeafNodes(root->right, target);
        if (left == NULL && right == NULL && root->val == target)
            return NULL;
        root->left = left;
        root->right = right;
        return root;
    }
};