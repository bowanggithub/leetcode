#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int myatoi(string s)
{
    if (s.size()==0)
        return 0;

    int i=0;
    while (i<s.size() && isspace(s[i]))
    {
        i++;
    }

    int sign;
    int result =0;
    if (s[i] == '-')
    {
        sign=-1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign=1;
        i++;
    }
    else
    {
        sign=1;
    }

    while (i<s.size() && isdigit(s[i]))
    {
        int digit = s[i]-'0';
        result = 10*result + digit;
        i++;
    }
    return result*sign;
}

int main()
{
    string x;
    cout << "enter string: ";
    cin >> x;
    cout << x << " : " << myatoi(x) << endl;
    return 0;
}
