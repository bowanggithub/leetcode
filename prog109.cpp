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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x, ListNode* n=nullptr) : val(x), next(n) {}
};

vector<int> listToVec(ListNode* head)
{
    vector<int> result;
    for (;head!=nullptr;head=head->next)
    {
        result.push_back(head->val);
    }
    return result;
}

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
    ListNode* n13=new ListNode(13);
    ListNode* n11=new ListNode(11,n13);
    ListNode* n9=new ListNode(9,n11);
    ListNode* n7=new ListNode(7,n9);
    ListNode* n5=new ListNode(5,n7);
    ListNode* n3=new ListNode(3,n5);
    ListNode* n1=new ListNode(1,n3);
    vector<int> vi=listToVec(n1);
    TreeNode* root=generateTree(vi,0,vi.size()-1);
    showTree(root);
    cout << endl;
}

