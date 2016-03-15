#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    if (candidates.size()==1)
    {
        vector<int> vi;
        if (target==candidates[0])
        {
            vi.push_back(candidates[0]);
            vector<vector<int>> vvi;
            vvi.push_back(vi);
            return vvi;
        }
        else
        {
            vector<vector<int>> vvi;
            return vvi;
        }
    }
    else if (target==0)
    {
        vector<int> vi;
        vector<vector<int>> vvi;
        vvi.push_back(vi);
        return vvi;
    }
    else if (target<0)
    {
        vector<vector<int>> vvi;
        return vvi;
    }
    else
    {
        int largest=candidates[candidates.size()-1];
        int n=min(target/largest,1);
        vector<vector<int>> vvi;
        for (int i=0;i<=n;i++)
        {
            vector<int> subcandidates(candidates.begin(),candidates.end()-1);
            vector<vector<int>> subvvi=
                    combinationSum2(subcandidates,target-i*largest);
            for (auto subvi : subvvi)
            {
                for (int j=0;j<i;j++)
                    subvi.push_back(largest);
                vvi.push_back(subvi);
            }
        }
        return vvi;
    }
}

int main()
{
    vector<int> candidates{1,1,2,5,6,7,10};
    int target=8;
    vector<vector<int>> comb=combinationSum2(candidates,target);
    for (int i=0;i<comb.size();i++)
    {
        for (int j=0;j<comb[i].size();j++)
        {
            cout << comb[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


