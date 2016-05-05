#include <iostream>
#include <string>
using namespace std;

int numDistinct(string s, string t)
{
    if (s.size()<t.size())
        return 0;
    else if (s.size()==t.size())
        return (s==t)?1:0;
    else
    {
        if (s[0]==t[0])
            return numDistinct(s.substr(1,s.size()-1),t.substr(1,t.size()-1)) 
                  +numDistinct(s.substr(1,s.size()-1),t);
        else
            return numDistinct(s.substr(1,s.size()-1),t);
    }
}

int main()
{
    string s="rabbbitttt";
    string t="rabbit";
    cout << numDistinct(s,t) << endl;
}
