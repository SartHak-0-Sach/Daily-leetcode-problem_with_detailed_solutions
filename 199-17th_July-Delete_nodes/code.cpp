/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> ans;
    bool ispresent(int target, vector<int> &to_delete)
    {
        for (int i = 0; i < to_delete.size(); i++)
        {
            if (target == to_delete[i])
            {
                return true;
            }
        }
        return false;
    }
    bool formans(TreeNode *root, vector<int> &to_delete)
    {
        if (root == NULL)
        {
            return false;
        }

        bool leftans = formans(root->left, to_delete);
        if (leftans)
            root->left = NULL;
        bool rightans = formans(root->right, to_delete);
        if (rightans)
            root->right = NULL;

        if (ispresent(root->val, to_delete))
        {
            if (root->left != NULL)
            {
                ans.push_back(root->left);
            }
            if (root->right != NULL)
            {
                ans.push_back(root->right);
            }
            return true;
        }
        return false;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (!ispresent(root->val, to_delete))
            ans.push_back(root);
        formans(root, to_delete);
        return ans;
    }
};