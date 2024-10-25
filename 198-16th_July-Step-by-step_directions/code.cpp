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
    TreeNode *LCA(TreeNode *root, int &s, int &e)
    {
        if (root == NULL)
            return NULL;
        if (root->val == s || root->val == e)
            return root;
        TreeNode *left = LCA(root->left, s, e);
        TreeNode *right = LCA(root->right, s, e);
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
    void LCATOStart(TreeNode *root, int val, string &curr, string &startpath)
    {
        if (!root)
            return;
        if (root->val == val)
        {
            startpath = curr;
            return;
        }
        curr.push_back('U');
        LCATOStart(root->left, val, curr, startpath);
        LCATOStart(root->right, val, curr, startpath);
        curr.pop_back();
    }
    void LCATODest(TreeNode *root, int val, string &curr, string &destPath)
    {
        if (!root)
            return;
        if (root->val == val)
        {
            destPath = curr;
            return;
        }
        curr.push_back('L');
        LCATODest(root->left, val, curr, destPath);
        curr.pop_back();
        curr.push_back('R');
        LCATODest(root->right, val, curr, destPath);
        curr.pop_back();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *lca = LCA(root, startValue, destValue);
        string startPath;
        string destPath;
        string curr;
        LCATOStart(lca, startValue, curr, startPath);
        LCATODest(lca, destValue, curr, destPath);
        return startPath + destPath;
    }
};