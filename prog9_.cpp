#include <iostream>
using namespace std;

int pow(int b,int x)
{
    int result =1;
    for (int i=0;i<x;i++)
    {
        result *= b;
    }
    return result;
}

bool isPalindrome(int x)
{
    if (x<0)
        return false;
    else if (x<10)
        return true;

    int len=0;
    while (x/pow(10,len) != 0)
        len++;

    if (x/pow(10,len-1) != x%10)
        return false;
    else
    {
        int truncx=(x%pow(10,len-1))/10;
        return isPalindrome(truncx);
    }
}

int main()
{
    cout << 0 << " " << isPalindrome(0) << endl;
    cout << -101 << " " << isPalindrome(-101) << endl;
    cout << 1001 << " " << isPalindrome(1001) << endl;
    cout << 1234321 << " " << isPalindrome(1234321) << endl;
    cout << 2134 << " " << isPalindrome(2134) << endl;
    return 0;
}

