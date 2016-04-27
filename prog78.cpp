#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> comb)
{
    for (auto vi:comb)
    {
        cout << "[";
        for (auto x:vi)
        {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    if (nums.size()==0)
    {
        result.push_back(vector<int>());
        return result;
    }
    else
    {
        vector<int> subnums(nums.begin(),nums.end()-1);
        auto subset1=subsets(subnums);
        auto subset2(subset1);
        for (auto& x:subset2)
            x.push_back(nums[nums.size()-1]);
        subset1.insert(subset1.end(), subset2.begin(),subset2.end());
        return subset1;
    }
}

int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>> subset=subsets(nums);
    print(subset);
}
