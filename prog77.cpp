#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> comb)
{
    for (auto vi:comb)
    {
        for (auto x:vi)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> combine(vector<int> nums, int k)
{
    vector<vector<int>> result;
    if (k>nums.size() || k<0) return result;
    else if (k==nums.size())
    {
        result.push_back(nums);
        return result;
    }
    else if (k==0)
    {
        result.push_back(vector<int>());
        return result;
    }
    else
    {
        vector<int> subnums(nums.begin(),nums.end()-1);
        auto subcombine1=combine(subnums,k);
        //cout << "sub1: " << endl;
        //print(subcombine1);
        auto subcombine2=combine(subnums,k-1);
        for (auto& x:subcombine2)
            x.push_back(nums[nums.size()-1]);
        //cout << "sub2: " << endl;
        //print(subcombine2);
        subcombine1.insert(subcombine1.end(),
                subcombine2.begin(),subcombine2.end());
        return subcombine1;
    }
}

int main()
{
    vector<int> nums{1,2,3,4,5};
    vector<vector<int>> comb=combine(nums,3);
    print(comb);
}

