#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode*l=nullptr, TreeNode* r=nullptr)
        : val(x), left(l), right(r) {}
};

void recoverTree(TreeNode* root)
{
    vector<TreeNode*> stack;
    TreeNode* prev=nullptr,*toExchangeLeft=nullptr,*toExchangeRight=nullptr;
    while (stack.size()!=0 || root != nullptr)
    {
        if (root != nullptr)
        {
            stack.push_back(root);
            root = root->left;
        }
        else
        {
            root=stack.back();
            stack.pop_back();
            if (prev!=nullptr)
            {
                if (toExchangeLeft==nullptr)
                {
                    if (prev->val>root->val)
                        toExchangeLeft=prev;
                }
                else
                {
                    if (root->val > toExchangeLeft->val)
                    {
                        toExchangeRight=prev;
                        break;
                    }
                }
            }
            prev=root;
            root=root->right;
        }
    }

    if (toExchangeRight==nullptr)
        toExchangeRight=prev;
    //cout << toExchangeLeft->val << " and " << toExchangeRight->val << endl;
    int v=toExchangeLeft->val;
    toExchangeLeft->val=toExchangeRight->val;
    toExchangeRight->val=v;
}

void showTree(TreeNode* root)
{
    if (root == nullptr);
    else
    {
        showTree(root->left);
        cout << root->val << " ";
        showTree(root->right);
    }
}

int main()
{
    TreeNode* n0=new TreeNode(0);
    TreeNode* n2=new TreeNode(2);
    TreeNode* n4=new TreeNode(4);
    TreeNode* n7=new TreeNode(7);
    TreeNode* n5=new TreeNode(5,n0,n2);
    TreeNode* n1=new TreeNode(1,n4,n7);
    TreeNode* n3=new TreeNode(3,n5,n1);
    showTree(n3);
    cout << endl;
    recoverTree(n3);
    showTree(n3);
    cout << endl;
}



