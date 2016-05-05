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

void flatten_recur(TreeNode* root)
{
    if (root==nullptr)
        return;
    TreeNode* left=root->left;
    TreeNode* right=root->right;
    TreeNode* curr=root;
    flatten_recur(left);
    root->left=nullptr;
    root->right=left;
    for (;curr->right!=nullptr;curr=curr->right);
    flatten_recur(right);
    curr->right=right;
}

void flatten_iter(TreeNode* root)
{
    if (root==nullptr)
        return;
    vector<TreeNode*> stack{root->right,root->left};
    TreeNode* curr=root;
    while (stack.size()!=0)
    {
        TreeNode* next=stack.back();
        stack.pop_back();
        if (next==nullptr)
            continue;
        else
        {
            curr->left=nullptr;
            curr->right=next;
            curr=curr->right;
            stack.push_back(curr->right);
            stack.push_back(curr->left);
        }
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
    TreeNode* n31=new TreeNode(3);
    TreeNode* n32=new TreeNode(4);
    TreeNode* n34=new TreeNode(6);
    TreeNode* n21=new TreeNode(2,n31,n32);
    TreeNode* n22=new TreeNode(5,nullptr,n34);
    TreeNode* n11=new TreeNode(1,n21,n22);
    flatten_iter(n11);
    showTreein(n11);
    cout << endl;
    showTreepre(n11);
    cout << endl;
}
    
