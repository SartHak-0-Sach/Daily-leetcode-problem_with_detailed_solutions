#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentPath) {
        if (node == nullptr) {
            return 0;
        }

        currentPath = currentPath ^ (1 << node->val);

        if (node->left == nullptr && node->right == nullptr) {
            // Check if the path is pseudo-palindromic
            return (currentPath & (currentPath - 1)) == 0 ? 1 : 0;
        }

        int leftCount = dfs(node->left, currentPath);
        int rightCount = dfs(node->right, currentPath);

        return leftCount + rightCount;
    }
};

int main() {
    // You can create a sample tree and test the function here if needed.
    return 0;
}
