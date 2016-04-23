#include <vector>
#include <iostream>
using namespace std;

bool canJump(vector<int>& nums)
{
    if (nums.size()==0) return false;
    int pos=0;
    int cover=nums[0];
    for (int i=0;i<nums.size() && i<=cover;++i)
    {
        if (i+nums[i]>cover)
            cover=i+nums[i];

        if (cover>nums.size()-1)
            return true;
    }
    return false;
}

int main()
{
    vector<int> a{2,3,1,1,4};
    cout << boolalpha << canJump(a) << endl;
    vector<int> b{3,2,1,0,4};
    cout << boolalpha << canJump(b) << endl;
    return 0;
}

