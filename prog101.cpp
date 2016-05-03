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

bool isSymmetric(TreeNode* p, TreeNode* q)
{
    if (p==nullptr && q==nullptr)
        return true;
    else if (p==nullptr && q!=nullptr || p!=nullptr && q==nullptr)
        return false;
    else
    {
        return (p->val==q->val &&
                isSymmetric(p->left,q->right) &&
                isSymmetric(p->right,q->left));
    }
}

bool isSymmetric_iter(TreeNode* p, TreeNode* q)
{
    vector<TreeNode*> stk1,stk2;
    vector<int> v1, v2;

    while (stk1.size()!=0 || p!=nullptr)
    {
        if (p!=nullptr)
        {
            stk1.push_back(p);
            p=p->left;
        }
        else
        {
            p=stk1.back();
            stk1.pop_back();
            v1.push_back(p->val);
            p=p->right;
        }
    }
    while (stk2.size()!=0 || q!=nullptr)
    {
        if (q!=nullptr)
        {
            stk2.push_back(q);
            q=q->right;
        }
        else
        {
            q=stk2.back();
            stk2.pop_back();
            v2.push_back(q->val);
            q=q->left;
        }
    }
    return (v1==v2);
}

int main()
{
    TreeNode* n31=new TreeNode(3);
    TreeNode* n32=new TreeNode(4);
    TreeNode* n33=new TreeNode(4);
    TreeNode* n34=new TreeNode(3);
    TreeNode* n21=new TreeNode(2,n31,n32);
    TreeNode* n22=new TreeNode(2,n33,n34);
    TreeNode* n11=new TreeNode(1,n21,n22);
    cout << boolalpha << isSymmetric(n21,n22) << endl;
    cout << boolalpha << isSymmetric_iter(n21,n22) << endl;
}
