#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, TreeNode* l=nullptr, TreeNode* r=nullptr):
        val(x), left(l),right(r) {}
};

vector<TreeNode*> generateTrees(int low, int high)
{
    vector<TreeNode*> v;
    if (low > high)
    {
        v.push_back(nullptr);
        return v;
    }
    if (low==high)
    {
        TreeNode* n=new TreeNode(low);
        v.push_back(n);
        return v;
    }

    for (int i=low; i<=high;i++)
    {
        vector<TreeNode*> vleft=generateTrees(low,i-1);
        vector<TreeNode*> vright=generateTrees(i+1,high);
        for (int l=0; l<vleft.size();l++)
        {
            for (int r=0; r<vright.size();r++)
            {
                TreeNode* root = new TreeNode(i,vleft[l],vright[r]);
                v.push_back(root);
            }
        }
    }
    return v;
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
    vector<TreeNode*> vt=generateTrees(1,3);
    cout << "number of different trees: " << vt.size() << endl;
}
