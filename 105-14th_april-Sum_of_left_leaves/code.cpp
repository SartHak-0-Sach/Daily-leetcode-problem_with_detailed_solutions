#include <iostream>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
};