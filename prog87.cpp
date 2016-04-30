#include <iostream>
#include <string>
using namespace std;

bool isScramble(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    if (s1==s2)
        return true;

    for (int i=1; i<s1.size(); i++)
    {
        if (isScramble(s1.substr(0,i),s2.substr(0,i)) && 
                isScramble(s1.substr(i,s1.size()-1),s2.substr(i,s2.size()-1)))
            return true;
        else if (isScramble(s1.substr(0,i), s2.substr(s2.size()-i,i)) && 
                isScramble(s1.substr(i,s1.size()-1), s2.substr(0,s2.size()-i)))
            return true;
    }
    return false;
}

int main()
{
    string s1="great";
    string s2="rgeat";
    string s3="rgtae";

    cout << boolalpha << s1 << " and " << s2 << ": " << isScramble(s1,s2) << endl;
    cout << boolalpha << s1 << " and " << s3 << ": " << isScramble(s1,s3) << endl;
    cout << boolalpha << s2 << " and " << s3 << ": " << isScramble(s2,s3) << endl;
}
