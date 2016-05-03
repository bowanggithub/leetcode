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

TreeNode* generateTree(vector<int>& nums, int low, int high)
{
    if (low > high)
        return nullptr;
    if (low==high)
    {
        TreeNode* n=new TreeNode(nums[low]);
        return n;
    }
    int mid=(low+high)/2;
    TreeNode* left=generateTree(nums,low,mid-1);
    TreeNode* right=generateTree(nums,mid+1,high);
    TreeNode* root=new TreeNode(nums[mid],left,right);
    return root;
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
    vector<int> vi{1,3,5,7,9,11,13,15};
    TreeNode* root=generateTree(vi,0,vi.size()-1);
    showTree(root);
    cout << endl;
}

