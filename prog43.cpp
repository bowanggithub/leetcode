#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string num1, string num2, int carry=0)
{
    int l1=num1.size(),l2=num2.size();
    if (l1>l2)
    {
        num2 = string(l1-l2,'0')+num2;
    }
    else
    {
        num1 = string(l2-l1,'0')+num1;
    }
    int l=max(l1,l2);
    if (l==0 && carry==0)
        return string("");
    else if (l==0 && carry==1)
        return string("1");
    else
    {
        int n1=num1[l-1]-'0';
        int n2=num2[l-1]-'0';
        int sum=(n1+n2+carry)%10;
        carry=(n1+n2)/10;
        return add(num1.substr(0,l-1),num2.substr(0,l-1),carry)+to_string(sum);
    }
}

string multiply(string num1, char c)
{
    int l=num1.size();
    if (l==0)
        return string("");
    int n1=num1[l-1]-'0';
    int n2=c-'0';
    int n=n1*n2;
    return add(multiply(num1.substr(0,l-1),c)+"0",to_string(n));
}

string multiply(string num1, string num2)
{
    int l2=num2.size();
    if (l2==0)
        return string("");
    char c=num2[l2-1];
    return add(multiply(num1,num2.substr(0,l2-1))+"0",multiply(num1,c));
}

int main()
{
    string s1="12345";
    string s2="123";
    //cout << add(s1,s2)<< endl;
    char c='3';
    cout << multiply(s1,s2) << endl;
    return 0;
}
