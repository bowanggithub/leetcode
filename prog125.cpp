#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    string d;
    for (int i=0; i<s.size();i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
            d.push_back(tolower(s[i]));
    }

    cout << d << endl;

    if (d.size()==0)
        return true;

    for (int i=0; i<d.size()/2; i++)
    {
        if (d[i]!= d[d.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    string s1="A man, a plan, a canal: Panama";
    string s2="race a car";
    cout << boolalpha << s1 << " : " << isPalindrome(s1) << endl;
    cout << boolalpha << s2 << " : " << isPalindrome(s2) << endl;
}
