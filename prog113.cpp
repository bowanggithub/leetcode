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

bool hasPathSum(TreeNode* root, int sum)
{
    if (root==nullptr)
        return sum==0;
    else
    {
        return (hasPathSum(root->left,sum-root->val) ||
                hasPathSum(root->right,sum-root->val) );
    }
}

void pathSum(TreeNode* root, int sum,vector<int> thisPath,
        vector<vector<int>>& allPaths)
{
    if (root->left==nullptr && root->right==nullptr && sum==root->val)
    {
        thisPath.push_back(root->val);
        allPaths.push_back(thisPath);
    }

    else
    {
        thisPath.push_back(root->val);
        //cout << root->val << " remain sum: " << sum-root->val << endl;
        if (root->left!=nullptr)
            pathSum(root->left,sum-root->val,thisPath,allPaths);
        if (root->right!=nullptr)
            pathSum(root->right,sum-root->val,thisPath,allPaths);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<int> thisPath;
    vector<vector<int>> allPaths;
    pathSum(root,sum,thisPath,allPaths);
    return allPaths;
}

int main()
{
    TreeNode* n41=new TreeNode(7);
    TreeNode* n42=new TreeNode(2);
    TreeNode* n43=new TreeNode(5);
    TreeNode* n44=new TreeNode(1);
    TreeNode* n31=new TreeNode(11,n41,n42);
    TreeNode* n32=new TreeNode(13);
    TreeNode* n33=new TreeNode(4,n43,n44);
    TreeNode* n21=new TreeNode(4,n31,nullptr);
    TreeNode* n22=new TreeNode(8,n32,n33);
    TreeNode* n11=new TreeNode(5,n21,n22);
    vector<vector<int>> allPaths=pathSum(n11,22);
    for (auto& vi:allPaths)
    {
        for (auto& x:vi)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
