#include <string>
#include <iostream>
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

int main()
{
    string haystack= "mrssissippi";
    string needle= "issi";
    cout << "position: " << strStr(haystack,needle) << endl;
    return 0;
}

