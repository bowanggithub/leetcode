//regular expression matching
#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p)
{
    cout << s << " : " << p << endl;
    if (p.size() == 0)
        return (s.size() == 0);
    else if (s.size() == 0 && p.size() == 2 && p[1]=='*')
    {
        return true;
    }
    else if (s.size() == 0)
    {
        return false;
    }
    else if (p.size() == 1 && p != ".")
    {
        return (s==p);
    }
    else if (p.size() == 1 && p == ".")
    {
        return (s.size() == 1);
    }
    else if (p[1] != '*')
    {
        string ssub=s.substr(1,s.size()-1);
        string psub=p.substr(1,p.size()-1);
        return ((s[0]==p[0]) || (p[0]=='.')) && isMatch(ssub,psub);
    }
    else if (p[1] == '*' && p[0] != s[0] && p[0] != '.')
    {
        string psub=p.substr(2,p.size()-2);
        return isMatch(s,psub);
    }
    else
    {
        string ssub=s.substr(1,s.size()-1);
        return isMatch(ssub,p);
    }
}

int main(int argc, char** argv)
{
    string s="ab",p=".*";
    //if (argc >2)
    //{
    //    s=argv[1];
    //    p=argv[2];
    //}
    cout << isMatch(s,p) << endl;
    return 0;
}
