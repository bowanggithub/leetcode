#include <iostream>
#include <vector>
using namespace std;

void move(vector<int>& nums)
{
    int n=nums.size();
    for (int i=0;i<n;i++)
    {
        int target = nums[i];
        while (target >0 && target <n && target != nums[target-1])
        {
            int new_target = nums[target-1];
            nums[target-1] = target;
            target = new_target;
        }
    }
}

int find_first(vector<int>& nums)
{
    int n=nums.size();
    for (int i=0;i<n;i++)
    {
        if (nums[i] != i+1)
            return i+1;
    }
    return n;
}

int main()
{
    vector<int> nums{3,4,-1,1};
    for (int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    move(nums);
    for (int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "first missing positive integer: " << find_first(nums) << endl;
    return 0;
}
