//two sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> numbers, int target)
{
    unordered_map<int,int> m;
    vector<int> ans;
    for (int i=0;i<numbers.size();i++)
    {
        if (m.find(numbers[i])==m.end())
        {
            m[target-numbers[i]]=i;
        }
        else
        {
            ans.push_back(m[numbers[i]]+1);
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}


int main()
{
    vector<int> numbers={2,7,11,15};
    int target=26;
    vector<int> ans=twoSum(numbers, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
