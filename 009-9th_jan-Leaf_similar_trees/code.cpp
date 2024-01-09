#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode
{
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*, vector<int>&)> collectLeafValues =
            [&](TreeNode* root, vector<int>& leafValues) {
                if (!root) {
                    return;
                }
                if (!root->left && !root->right) {
                    leafValues.push_back(root->val);
                }
                collectLeafValues(root->left, leafValues);
                collectLeafValues(root->right, leafValues);
            };

        vector<int> leafValues1, leafValues2;
        collectLeafValues(root1, leafValues1);
        collectLeafValues(root2, leafValues2);

        return leafValues1 == leafValues2;
    }
};
