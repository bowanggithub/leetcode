#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums)
{
    int n=nums[0];
    if (nums.size()<=n+1)
        return 1;
    else
    {
        int minstep=10000;
        for (int i=1;i<=n;i++)
        {
            vector<int> sub(nums.begin()+i,nums.end());
            int ni=jump(sub);
            minstep = min(minstep,ni);
        }
        return minstep+1;
    }
}

int main()
{
    vector<int> nums{1,1,1,2,1,1,2,1,1,1};
    cout << "steps:" << jump(nums) << endl;
    return 0;
}


