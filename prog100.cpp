#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p==nullptr && q==nullptr)
        return true;
    else if (p!=nullptr || q==nullptr)
        return false;
    else if (p==nullptr || q!=nullptr)
        return false;
    else
    {
        return (p->val==1->val &&
                isSameTree(p->left,q->left) &&
                isSameTree(p->right,q->right));
    }
}
