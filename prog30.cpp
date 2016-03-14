#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool match(string sub, vector<string> words)
{
    map<string, int> m;
    int n=words.size();
    int l=words[0].size();
    for (auto x : words)
    {
        if (m.find(x) == m.end())
            m[x]=1;
        else
            m[x]++;
    }
    //for (auto iter=m.begin();iter!=m.end();iter++)
    //{
    //    cout << iter->first << " : " << iter->second << endl;
    //}
    for (int i=0;i<n;i++)
    {
        //cout << sub.substr(i*l,l) << endl;
        if (m.find(sub.substr(i*l,l)) == m.end())
        {
            return false;
        }
        else
            m[sub.substr(i*l,l)]--;
    }
    //for (auto iter=m.begin();iter!=m.end();iter++)
    //{
    //    cout << iter->first << " : " << iter->second << endl;
    //}
    for (auto iter=m.begin();iter!=m.end();iter++)
    {
        if (iter->second != 0)
            return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string> words)
{
    vector<int> results;
    int n=words.size();
    int l=words[0].size();
    for (int i=0;i<=s.size()-n*l;i++)
    {
        if (match(s.substr(i,n*l),words))
            results.push_back(i);
    }
    return results;
}

int main()
{
    string s="barfoothefoobarmanfoobarfoobarfoo";
    vector<string> words{"foo","bar"};
    //cout << boolalpha << match(s,words) << endl;
    vector<int> results = findSubstring(s,words);
    for (int i=0;i<results.size();i++)
    {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}
