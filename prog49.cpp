#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string,vector<string>> m;
    for (auto s : strs)
    {
        string pattern=s;
        sort(pattern.begin(),pattern.end());
        if (m.find(pattern) == m.end())
        {
            m[pattern]={};
            m[pattern].push_back(s);
        }
        else
        {
            m[pattern].push_back(s);
            sort(m[pattern].begin(),m[pattern].end());
        }
    }

    vector<vector<string>> results;
    for (auto iter=m.begin(); iter != m.end(); iter++)
    {
        results.push_back(iter->second);
    }
    return results;
}

void show(vector<vector<string>> vvs)
{
    for (auto vs : vvs)
    {
        for (auto s : vs)
        {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    show(groupAnagrams(strs));
    return 0;
}


