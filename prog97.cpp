#include <iostream>
#include <string>
using namespace std;

bool isInterleave(string s1,string s2, string s3)
{
    cout << "compare: " << s1 << " : " << s2 << " with " << s3 << endl;
    if (s1.size()==0)
        return s2==s3;
    else if (s2.size()==0)
        return s1==s3;
    else if (s3.size()==0)
        return (s1.size()==0 && s2.size()==0);

    else if (s3[0]==s2[0] && s3[0]==s1[0])
        return isInterleave(s1,s2.substr(1,s2.size()-1),s3.substr(1,s3.size()-1))
            || isInterleave(s1.substr(1,s1.size()-1),s2,s3.substr(1,s3.size()-1));
    else if (s3[0]==s1[0] && s3[0]!=s2[0])
        return isInterleave(s1.substr(1,s1.size()-1),s2,s3.substr(1,s3.size()-1));
    else if (s3[0]==s2[0] && s3[0]!=s1[0])
        return isInterleave(s1,s2.substr(1,s2.size()-1),s3.substr(1,s3.size()-1));
    else
        return false;
}

int main()
{
    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
    string s4="aadbbbaccc";
    cout << boolalpha << isInterleave(s1,s2,s3) << endl;
    cout << boolalpha << isInterleave(s1,s2,s4) << endl;
}

    
