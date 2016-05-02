#include <iostream>
#include <string>
using namespace std;

int numDecodings(string s)
{
    if (s.size()==0)
        return 0;
    else if (s.size()==1)
        return (s=="0")?0:1;
    else if (s.size()==2)
    {
        int n=stoi(s);
        return (n>26 || n<0)?1:2;
    }
    else
    {
        int a=numDecodings(s.substr(0,1))*numDecodings(s.substr(1,s.size()-1));
        //cout <<s.substr(0,1) << ":" <<numDecodings(s.substr(0,1))<<"*" <<s.substr(1,s.size()-1)<<":"<<numDecodings(s.substr(1,s.size()-1))<< endl;
        int b=(numDecodings(s.substr(0,2))-1)*numDecodings(s.substr(2,s.size()-2));
        //cout <<numDecodings(s.substr(0,2))<<"*" <<numDecodings(s.substr(2,s.size()-2))<< endl;
        return a+b;
    }
}

int main()
{
    string s="1234567";
    cout << numDecodings(s) << endl;
}


