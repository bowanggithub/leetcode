#include <iostream>
#include <vector>
using namespace std;

int searchLowerRange(vector<int> nums, int low, int high,int value)
{
    if (high==low)
    {
        return (value==nums[low])?low:-1;
    }
    int mid=(low+high)/2;
    if (nums[mid]<value)
    {
        //cout << mid+1 << " " << high << endl;
        return searchLowerRange(nums,mid+1,high,value);
    }
    else
    {
        //cout << low << " " << mid << endl;
        return searchLowerRange(nums,low,mid,value);
    }
}
int searchHigherRange(vector<int> nums, int low, int high,int value)
{
    if (high==low)
    {
        return (value==nums[low])?low:-1;
    }
    int mid=(low+high)/2;
    if (nums[mid+1]>value)
    {
        //cout << low << " " << mid << endl;
        return searchHigherRange(nums,low,mid,value);
    }
    else
    {
        //cout << mid+1 << " " << high << endl;
        return searchHigherRange(nums,mid+1,high,value);
    }
}

int main()
{
    vector<int> nums{5,7,7,8,8,10};
    int n;
    cout << "enter n:";
    cin >> n;
    cout << searchLowerRange(nums,0,nums.size()-1,n) << endl;
    cout << searchHigherRange(nums,0,nums.size()-1,n) << endl;
    return 0;
}

