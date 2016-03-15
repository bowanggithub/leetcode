#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(const string& s)
{
    if (s.size()==0)
        return s;

    string result;
    char c=s[0];
    int i;
    for (i=1; i<s.size() && s[i]==c; i++);
    return to_string(i)+string(1,c)+countAndSay(s.substr(i,s.size()-i));
}

int main()
{
    string s="1";
    vector<string> vs;
    vs.push_back(s);
    for (int i=0;i<10;i++)
    {
        s=countAndSay(s);
        vs.push_back(s);
    }
    for (int i=0;i<vs.size();i++)
    {
        cout << vs[i] << " ";
    }
    cout << endl;
    return 0;
}

