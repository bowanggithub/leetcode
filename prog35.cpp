#include <vector>
#include <iostream>
using namespace std;

int searchInsertPosition(vector<int> nums, int low, int high, int val)
{
    if (high==low)
        return (nums[low]>=val)?low:low+1;

    int mid=(low+high)/2;
    if (nums[mid+1]>val)
        return searchInsertPosition(nums,low,mid,val);
    else
        return searchInsertPosition(nums,mid+1,high,val);
}

int main()
{
    vector<int> nums{1,3,5,6};
    cout << "enter number to insert: ";
    int n;
    cin >> n;
    cout << "pos is: " << searchInsertPosition(nums,0,nums.size()-1,n) << endl;
    return 0;
}
