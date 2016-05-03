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

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    vector<TreeNode*> prev;
    vector<int> currlevel;
    if (root==nullptr)
        return result;
    prev.push_back(root);
    currlevel.push_back(root->val);
    result.push_back(currlevel);

    while (prev.size()!=0)
    {
        vector<TreeNode*> newLevel;
        currlevel={};
        for (auto x:prev)
        {
            if (x->left!=nullptr)
            {
                newLevel.push_back(x->left);
                currlevel.push_back(x->left->val);
            }
            if (x->right!=nullptr)
            {
                newLevel.push_back(x->right);
                currlevel.push_back(x->right->val);
            }
        }
        prev=newLevel;
        if (currlevel.size()!=0)
            result.push_back(currlevel);
    }
    return result;
}

int main()
{
    TreeNode* n33=new TreeNode(15);
    TreeNode* n34=new TreeNode(7);
    TreeNode* n21=new TreeNode(9);
    TreeNode* n22=new TreeNode(20,n33,n34);
    TreeNode* n11=new TreeNode(3,n21,n22);
    vector<vector<int>> result=levelOrder(n11);
    for (auto vi:result)
    {
        for (auto x:vi)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

            
