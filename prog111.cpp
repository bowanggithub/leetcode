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

int mindepth(TreeNode* root)
{
    if (root ==nullptr)
        return 0;
    else
    {
        int left=1+depth(root->left);
        int right=1+depth(root->right);
        return left<right?left:right;
    }
}

