#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left,*right,*next;
    TreeLinkNode(int x,TreeLinkNode* l=nullptr,
            TreeLinkNode* r=nullptr, TreeLinkNode* n=nullptr)
        : val(x), left(l), right(r), next(n) {}
};

void connect(TreeLinkNode* root)
{
    if (root==nullptr) return;

    vector<TreeLinkNode*> prevLevel{root};
    vector<vector<TreeLinkNode*>> levels{prevLevel};
    while (prevLevel.size()!=0)
    {
        vector<TreeLinkNode*> currLevel;
        for (auto x:prevLevel)
        {
            if (x->left!=nullptr)
                currLevel.push_back(x->left);
            if (x->right!=nullptr)
                currLevel.push_back(x->right);
        }
        if (currLevel.size()!=0)
            levels.push_back(currLevel);
        prevLevel=currLevel;
    }

    for (auto v:levels)
    {
        for (int i=0; i<v.size()-1;i++)
        {
            v[i]->next=v[i+1];
        }
    }
}

void showTreein(TreeLinkNode* root)
{
    if (root == nullptr);
    else
    {
        showTreein(root->left);
        cout << root->val << " ";
        showTreein(root->right);
    }
}

void showTreepre(TreeLinkNode* root)
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
    TreeLinkNode* n31=new TreeLinkNode(4);
    TreeLinkNode* n32=new TreeLinkNode(5);
    TreeLinkNode* n34=new TreeLinkNode(7);
    TreeLinkNode* n21=new TreeLinkNode(2,n31,n32);
    TreeLinkNode* n22=new TreeLinkNode(3,nullptr,n34);
    TreeLinkNode* n11=new TreeLinkNode(1,n21,n22);
    showTreein(n11);
    cout << endl;
    showTreepre(n11);
    cout << endl;
    connect(n11);
}

