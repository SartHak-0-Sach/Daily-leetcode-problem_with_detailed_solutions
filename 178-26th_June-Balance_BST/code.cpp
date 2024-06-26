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
public:
    // time/space: O(n)/O(n)
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return buildBST(nodes, 0, nodes.size() - 1);
    }
private:
    void inorder(TreeNode* node, vector<TreeNode*>& nodes) {
        // terminate
        if (node == NULL) return;

        // enumerate
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
    TreeNode* buildBST(vector<TreeNode*>& nodes, int left, int right) {
        // terminate
        if (left > right) return NULL;

        // enumerate
        int mid = left + ((right - left) >> 1);
        TreeNode* node = nodes[mid];
        node->left = buildBST(nodes, left, mid - 1);
        node->right = buildBST(nodes, mid + 1, right);
        return node;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();