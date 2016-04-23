#include <vector>
#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    if (nums.size()==0) return 0;
    int max_end_here=nums[0];
    int max=nums[0];
    int idx1=0,idx2=0;
    for (int i=1;i<nums.size();++i)
    {
        if (max_end_here <0)
        {
            idx1=idx2=i;
            max_end_here = nums[i];
        }
        else
        {
            idx2++;
            max_end_here+=nums[i];
        }
        max = (max>max_end_here)?max:max_end_here;
    }
    cout << "from index " << idx1 << " to index " << idx2 << endl;
    cout << "max= " << max << endl;
    return max;
}

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4,1,2,3,4,5};
    maxSubArray(nums);
    return 0;
}
