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

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder)
{
    if (postorder.size()==0)
        return nullptr;
    else if (postorder.size()==1)
    {
        return (new TreeNode(postorder[0]));
    }
    else
    {
        int rootval=postorder.back();
        auto it=find(inorder.begin(),inorder.end(),rootval);
        vector<int> subinorder1(inorder.begin(),it);
        vector<int> subinorder2(it+1,inorder.end());
        int size1=subinorder1.size();
        vector<int> subpostorder1(postorder.begin(),postorder.begin()+size1);
        vector<int> subpostorder2(postorder.begin()+size1,postorder.end()-1);
        TreeNode* subtree1=buildTree(subpostorder1,subinorder1);
        TreeNode* subtree2=buildTree(subpostorder2,subinorder2);
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

void showTreepost(TreeNode* root)
{
    if (root == nullptr);
    else
    {
        showTreepost(root->left);
        showTreepost(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    vector<int> in{1,3,4,5,6,7,9};
    vector<int> post{1,4,3,6,9,7,5};
    TreeNode* t=buildTree(post,in);
    showTreein(t);
    cout << endl;
    showTreepost(t);
    cout << endl;
}

