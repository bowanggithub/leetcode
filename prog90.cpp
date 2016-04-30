#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
//#include <pair>
using namespace std;

vector<vector<int>> subsetofmap(map<int,int> m);
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    map<int,int> m;
    for (int i=0; i<nums.size();i++)
    {
        if (m.find(nums[i])==m.end())
            m[nums[i]]=1;
        else
            m[nums[i]]++;
    }

    result=subsetofmap(m);
    return result;
}

vector<vector<int>> subsetofmap(map<int,int> m)
{
    for (auto iter=m.begin();iter!=m.end();iter++)
        cout << iter->first << " ";
    cout << endl;
    vector<vector<int>> result;
    if (m.empty())
    {
        result.push_back(vector<int>());
        return result;
    }
    else
    {
        auto lastpair=m.end();
        lastpair--;
        int elem=lastpair->first;
        int cnt=lastpair->second;
        m.erase(elem);
        vector<vector<int>> subsubset=subsetofmap(m);
        for (auto& x:subsubset)
        {
            for (int i=0; i<=cnt; i++)
            {
                vector<int> newelem(x.begin(),x.end());
                newelem.insert(newelem.end(),i,elem);
                result.push_back(newelem);
            }
        }
        return result;
    }
}

int main()
{
    vector<int> nums{1,2,2};
    vector<vector<int>> subset=subsetsWithDup(nums);
    for (auto vi: subset)
    {
        cout << "[";
        for (auto x: vi)
            cout << x << " ";
        cout << "]" << endl;
    }
}

