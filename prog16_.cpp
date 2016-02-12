#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void display(const vector<int>& nums)
{
    cout << "{";
    for (int i=0;i<nums.size()-1;i++)
    {
        cout << nums[i] << ", ";
    }
    cout << nums[nums.size()-1] << "}" << endl;
}

int twoSumClosest(const vector<int>& nums, int target)
{
    if (nums.size() < 2)
        return 1000;
    int distance = nums[0] + nums[1] - target;
    for (int i=0;i<nums.size();i++)
    {
        for (int j=i+1;j<nums.size();j++)
        {
            if (fabs(nums[i]+nums[j]-target) < fabs(distance))
                distance = nums[i] + nums[j] - target;
        }
    }
    return distance;
}

int threeSumClosest(const vector<int>& nums, int target)
{
    int distance3=nums[0]+nums[1]+nums[2]-target;
    for (int i=0;i<nums.size();i++)
    {
        vector<int> subnums(nums.begin()+i+1,nums.end());
        int distance = twoSumClosest(subnums,target-nums[i]);
        if (fabs(distance) < fabs(distance3))
            distance3=distance;
    }
    return target+distance3;
}

int main()
{
    vector<int> S={-4,-1,1,2};
    cout << threeSumClosest(S,1) << endl;
    vector<int> A={0};
    cout << twoSumClosest(A,1) << endl;
    return 0;
}

