#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    int m=haystack.size();
    int n=needle.size();
    int i;
    for (i=0;i<=m-n;i++)
    {
        if (haystack.substr(i,n) == needle)
            break;
    }
    return i;
}


bool isMatch(string s, string p)
{
    if (p=="*")
        return true;
    else if (p.size()==0)
        return (s.size()==0);
    else if (p[0] != '*')
    {
        return (s[0]==p[0] || p[0]=='?') 
            && isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
    }
    else if (p[p.size()-1] != '*')
    {
        return (s[s.size()-1]==p[p.size()-1] || p[p.size()-1]=='?')
            && isMatch(s.substr(0,s.size()-1),p.substr(0,p.size()-1));
    }
    else
    {
        int nextstar;
        for (nextstar=1; p[nextstar] != '*'; nextstar++);
        string sub=p.substr(1,nextstar-1);
        int match=strStr(s,sub);
        if (match >s.size()-sub.size())
            return false;
        else return isMatch(s.substr(match+nextstar-1,s.size()-match-nextstar+1),
                p.substr(nextstar,p.size()-nextstar));
    }
}

int main()
{
    cout << boolalpha << isMatch("aa","a") << endl;
    cout << boolalpha << isMatch("aa","aa") << endl;
    cout << boolalpha << isMatch("aaa","aa") << endl;
    cout << boolalpha << isMatch("aa","*") << endl;
    cout << boolalpha << isMatch("aa","a*") << endl;
    cout << boolalpha << isMatch("ab","?*") << endl;
    cout << boolalpha << isMatch("aab","c*a*b") << endl;
    cout << boolalpha << isMatch("abc","*a*bc**") << endl;
    return 0;
}

