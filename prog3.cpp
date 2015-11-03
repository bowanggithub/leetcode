//longest substring without repeating characters
#include <iostream>
#include <string>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char,int> m;
    int pos=0;
    int templongest=0,longest=0;
    for (int i=0;i< s.size();i++)
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

        if (longest< templongest)
        {
            longest=templongest;
            pos=i;
        }
    }
    cout << "pos is " << pos << endl;
    return longest;
}

int main()
{
    string s="bbabcdb";
    int l=lengthOfLongestSubstring(s);
    cout << "l is " << l << endl;
    return 0;
}


