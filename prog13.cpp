//roman to integer
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int helper(char c)
{
    int val;
    if (c=='I')
        val=1;
    else if (c=='V')
        val=5;
    else if (c=='X')
        val=10;
    else if (c=='L')
        val=50;
    else if (c=='C')
        val=100;
    else if (c=='D')
        val=500;
    else if (c=='M')
        val=1000;

    return val;
}
int romanToInt(string s)
{
    if (s.size() == 0)
        return 0;
    else if (s.size() == 1)
        return helper(s[0]);
    int result=0;
    if (helper(s[0]) < helper(s[1]))
    {
        string sub=s.substr(2,s.size()-2);
        result = result - helper(s[0]) + helper(s[1]) + romanToInt(sub);
    }
    else
    {
        string sub=s.substr(1,s.size()-1);
        result = result + helper(s[0]) + romanToInt(sub);
    }
    return result;
}

int main(int argc, char** argv)
{
    string roman="XL";
    if (argc > 1)
        roman=argv[1];

    cout << roman << " : " << romanToInt(roman) << endl;
    return 0;
}
