//longest common prefix
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string prefix;
    if (strs.size()==0)
        return prefix;

    bool match=true;
    for (int i=0; i<strs[0].size(),match; i++)
    {
        char c=strs[0][i];
        for (int j=0; j<strs.size(); j++)
        {
            if (c != strs[j][i])
                match=false;
        }
        
        if (match)
            prefix += c;
        cout << i << " " <<prefix << endl;
    }
    return prefix;
}

int main()
{
    vector<string> s={"abab", "aba", "abc"};
    cout << longestCommonPrefix(s) << endl;
    return 0;
}

