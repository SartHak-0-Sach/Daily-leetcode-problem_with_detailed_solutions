#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> map;
    unordered_set<int> children;

    for (auto &arr : descriptions)
    {
        int parent = arr[0], child = arr[1], isLeft = arr[2];
        children.insert(child);
        if (map.find(parent) == map.end())
        {
            map[parent] = new TreeNode(parent);
        }
        if (map.find(child) == map.end())
        {
            map[child] = new TreeNode(child);
        }
        if (isLeft == 1)
        {
            map[parent]->left = map[child];
        }
        else
        {
            map[parent]->right = map[child];
        }
    }

    int root = -1;
    for (auto &arr : descriptions)
    {
        if (children.find(arr[0]) == children.end())
        {
            root = arr[0];
            break;
        }
    }

    return map[root];
}