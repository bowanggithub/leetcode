#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int pos = 0;
    int n=nums.size();
    for (int i=0;i<nums.size();i++)
    {
        if (nums[i] != val)
        {
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
}

int main()
{
    vector<int> nums= {1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,6,7,8,9,0};
    for (int i=0;i<nums.size();i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    int n = removeElement(nums,2);
    cout << "n= " << n << endl;
    for (int i=0;i<n;i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
