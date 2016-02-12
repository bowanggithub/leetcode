#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string prefix;
    if (strs.size() == 0)
        return prefix;

    bool match=true;
    for (int i=0;i<strs[0].size();i++)
    {
        char c=strs[0][i];
        for (int j=1;j<strs.size();j++)
        {
            if (c != strs[j][i])
                match=false;
        }
        if (match)
            prefix += c;
    }
    return prefix;
}

int main()
{
    vector<string> s={"abab","aba","abc"};
    cout << longestCommonPrefix(s) << endl;
    return 0;
}
