#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums)
{
    int next0=0;
    int next2=nums.size()-1;

    for (int i=0; i<=next2; i++)
    {
        if (nums[i]==0)
        {
            nums[i]=nums[next0];
            nums[next0]=0;
            next0++;
        }
        else if (nums[i]==2)
        {
            nums[i]=nums[next2];
            nums[next2]=2;
            next2--;
            i--;
        }
    }
}

int main()
{
    vector<int> nums{1,2,0,0,2,1,2,1,2,1,2,0,0,0,1,2,1,0,2,0,0,2,1};
    for (auto x : nums)
        cout << x << ", ";
    cout << endl;
    sortColors(nums);
    for (auto x : nums)
        cout << x << ", ";
    cout << endl;
    return 0;
}
