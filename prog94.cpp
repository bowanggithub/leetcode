#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x,TreeNode* l=nullptr, TreeNode* r=nullptr)
        : val(x), left(l), right(r) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<TreeNode*> stack;
    vector<int> v;

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
            v.push_back(root->val);
            root= root->right;
        }
    }
    return v;
}

int main()
{
    TreeNode* n3=new TreeNode(3);
    TreeNode* n2=new TreeNode(2,n3);
    TreeNode* n1=new TreeNode(1,nullptr,n2);
    vector<int> v=inorderTraversal(n1);
    for (auto& x:v)
        cout << x << " ";
    cout << endl;
}
