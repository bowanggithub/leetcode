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

vector<int> toVec(TreeNode* root)
{
    vector<int> vec;
    if (root==nullptr)
        return vec;
    else
    {
        vector<int> lvec=toVec(root->left);
        vector<int> rvec=toVec(root->right);
        lvec.push_back(root->val);
        lvec.insert(lvec.end(),rvec.begin(),rvec.end());
        return lvec;
    }
}

bool sortOrNot(vector<int>& v)
{
    for (int i=0; i<v.size()-1; i++)
        if (v[i]>=v[i+1])
            return false;
    return true;
}

bool isValidBST(TreeNode* root)
{
    vector<int> vec=toVec(root);
    return sortOrNot(vec);
}

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
    vector<TreeNode*> vt=generateTrees(1,5);
    for (auto& x:vt)
    {
        showTree(x);
        cout << endl;
    }
    for (auto& x:vt)
        cout << boolalpha << isValidBST(x) << endl;
}
