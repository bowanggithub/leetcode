#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l=nullptr, TreeNode* r=nullptr)
        : val(x), left(l), right(r) {}
};

int depth(TreeNode* root)
{
    if (root ==nullptr)
        return 0;
    else
    {
        int left=1+depth(root->left);
        int right=1+depth(root->right);
        return left>right?left:right;
    }
}

bool isBalanced(TreeNode* root)
{
    if (root==nullptr)
        return true;
    else
    {
        int l=depth(root->left);
        int r=depth(root->right);
        if (left-right>1 || right-left>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
}


