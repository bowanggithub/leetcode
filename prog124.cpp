#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l=nullptr, TreeNode* r=nullptr)
        : val(x), left(l), right(r) {}
};

int maxSum(TreeNode* root)
{
    if (root==nullptr)
        return 0;

    int left=maxSum(root->left);
    int right=maxSum(root->right);
    return (left>right)?root->val+left:root->val+right;
}

int maxPathSum(TreeNode* root)
{
    if (root==nullptr)
        return 0;

    int left=maxSum(root->left);
    int right=maxSum(root->right);

    if (left>0 && right>0)
        return root->val+left+right;
    else if (left>0 && right<=0)
        return root->val+left;
    else if (left<=0 && right>0)
        return root->val+right;
    else
        return root->val;
}

int main()
{
    TreeNode* t21=new TreeNode(2);
    TreeNode* t22=new TreeNode(3);
    TreeNode* t11=new TreeNode(1,t21,t22);
    cout << "max= " << maxPathSum(t11) << endl;
}
