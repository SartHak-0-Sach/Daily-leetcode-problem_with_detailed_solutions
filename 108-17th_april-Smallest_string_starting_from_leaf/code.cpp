#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
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
    void func(TreeNode *root, string curr, string &res)
    {
        // add current value of node to string
        curr += (root->val + 'a');

        // check if it is a leaf node or not
        // if it is, then reverse string curr and
        // check for lexico
        // if lexico then update res
        // else just return
        if (root->left == NULL && root->right == NULL)
        {
            reverse(curr.begin(), curr.end());

            if (curr.length() > 0 && curr < res)
                res = curr;

            // reverse(curr.begin(),curr.end());

            // we can avoid reversing string curr again
            // as we are not passing by reference

            return;
        }

        // call for both left and right nodes
        if (root->left)
            func(root->left, curr, res);
        if (root->right)
            func(root->right, curr, res);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string res = "{}";
        func(root, "", res);
        return res;
    }
};