#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l= nullptr, TreeNode* r=nullptr)
        : val(x), left(l), right(r) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size()==0)
        return nullptr;
    else if (preorder.size()==1)
    {
        return (new TreeNode(preorder[0]));
    }
    else
    {
        int rootval=preorder[0];
        auto it=find(inorder.begin(),inorder.end(),rootval);
        vector<int> subinorder1(inorder.begin(),it);
        vector<int> subinorder2(it+1,inorder.end());
        int size1=subinorder1.size();
        vector<int> subpreorder1(preorder.begin()+1,preorder.begin()+size1+1);
        vector<int> subpreorder2(preorder.begin()+1+size1,preorder.end());
        TreeNode* subtree1=buildTree(subpreorder1,subinorder1);
        TreeNode* subtree2=buildTree(subpreorder2,subinorder2);
        return (new TreeNode(rootval,subtree1,subtree2));
    }
}

void showTreein(TreeNode* root)
{
    if (root == nullptr);
    else
    {
        showTreein(root->left);
        cout << root->val << " ";
        showTreein(root->right);
    }
}

void showTreepre(TreeNode* root)
{
    if (root == nullptr);
    else
    {
        cout << root->val << " ";
        showTreepre(root->left);
        showTreepre(root->right);
    }
}

int main()
{
    vector<int> in{1,3,4,5,6,7,9};
    vector<int> pre{5,3,1,4,7,6,9};
    TreeNode* t=buildTree(pre,in);
    showTreein(t);
    cout << endl;
    showTreepre(t);
    cout << endl;
}

