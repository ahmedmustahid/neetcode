#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using std::cout;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height = -1;
bool isBal{true};

int dfs(TreeNode *node)
{
    if (node == nullptr)
        return -1;
    // height += 1;
    int hLeft = dfs(node->left);
    int hRight = dfs(node->right);

    if (abs(hLeft - hRight) > 1)
        isBal = false;
    return std::max(hLeft, hRight) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    dfs(root);
    return isBal;
}

int main()
{
    vector<int> v{3, 9, 20, NULL, NULL, 15, 7};
    vector<TreeNode> treeVec;

    int maxId = v.size() - 1;

    for (size_t i = 0; i < v.size(); ++i)
    {
        TreeNode tn = TreeNode(v[i]);
        treeVec.push_back(tn);
    }

    TreeNode *root = &treeVec[0];
    for (size_t i = 0; i < std::floor(maxId / 2) + 1; ++i)
    {
        TreeNode *parent = &treeVec[i];
        TreeNode *child1 = &treeVec[2 * i + 1];
        TreeNode *child2 = &treeVec[2 * i + 2];

        if ((*child1).val == NULL)
            child1 = nullptr;
        if ((*child2).val == NULL)
            child2 = nullptr;
        parent->left = child1;
        parent->right = child2;
    }

    // std::cout << isBalanced(root) << "\n";

    TreeNode node = TreeNode(1, nullptr, nullptr);
    std::cout << isBalanced(&node) << "\n";
}