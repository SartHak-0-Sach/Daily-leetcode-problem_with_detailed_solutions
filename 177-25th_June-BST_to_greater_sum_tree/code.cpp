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
class Solution {
private:
    int sum = 0;

    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->right);  // Traverse the right subtree
            sum += root->val;  // Update the sum
            root->val = sum;  // Update the current node's value
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();