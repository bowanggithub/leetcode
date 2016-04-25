#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isNumeric(string s)
{
    bool hasPoint=false;
    bool hasE=false;

    int idx=0;
    for (;isspace(s[idx]) && idx<s.size();idx++);
    if (s[idx]=='+' || s[idx]=='-') idx++;
    for (;idx<s.size(); idx++)
    {
        if (s[idx]=='.')
        {
            if (hasE || hasPoint)
                return false;
            hasPoint=true;
            continue;
        }
        if (s[idx]=='e')
        {
            if (hasE || idx==0)
                return false;
            idx++;
            if (s[idx]=='+' || s[idx]=='-') idx++;
            if (!isdigit(s[idx])) return false;
            hasE=true;
            continue;
        }
        if (isspace(s[idx]))
        {
            for (int i=idx; i<s.size();i++)
                if (!isspace(s[i])) return false;
            return true;
        }
        if (!isdigit(s[idx]))
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    string s="1";
    if (argc>1)
        s=argv[1];
    cout << s << ": " << boolalpha << isNumeric(s) << endl;
    return 0;
}
