#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> lengthOfLongestSubstring(string s)
{
    map<char,int> m;
    int pos=0;
    int templongest=0,longest=0;
    for (int i=0;i<s.size();i++)
    {
        if (m.find(s[i]) == m.end())
        {
            m[s[i]]=i;
            templongest++;
        }
        else if (i-m[s[i]] <= templongest)
        {
            templongest=i-m[s[i]];
            m[s[i]]=i;
        }
        else
        {
            templongest++;
            m[s[i]]=i;
        }

        if (longest < templongest)
        {
            longest = templongest;
            pos=i;
        }
    }

    vector<int> sub;
    sub.push_back(pos);
    sub.push_back(longest);
    return sub;
}


int main()
{
    string s="bbabcdb";
    vector<int> sub = lengthOfLongestSubstring(s);
    int l=sub[1]; int pos=sub[0];
    cout << "length is " << l << " ending at " << pos << endl;
    return 0;
}
