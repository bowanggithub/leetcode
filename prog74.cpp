#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int searchVertical(vector<vector<int>> & nums, int low, int high, int val)
{
    if (high==low)
        return low;
    int mid=(low+high)/2;
    if (nums[mid+1][0]>val)
        return searchVertical(nums, low, mid, val);
    else
        return searchVertical(nums, mid+1, high, val);
}

bool searchHorizontal(vector<int>& nums, int low, int high, int val)
{
    if (high==low)
        return (nums[low]==val);

    int mid=(low+high)/2;
    if (nums[mid+1]>val)
        return searchHorizontal(nums,low,mid,val);
    else
        return searchHorizontal(nums, mid+1, high, val);
}

int main(int argc, char** argv)
{
    vector<vector<int>> nums{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int val=3;
    if (argc >1)
        val=atoi(argv[1]);
    int row=searchVertical(nums,0,nums.size()-1,val);
    cout << boolalpha << searchHorizontal(nums[row],0,nums[row].size()-1,val)
         << endl;
}
