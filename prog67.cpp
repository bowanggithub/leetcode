#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b,int carry=0)
{
    if (a.size() > b.size())
        b=string(a.size()-b.size(),'0')+b;
    else if (b.size() > a.size())
        a=string(b.size()-a.size(),'0')+a;
    cout << "adding: " << a  << " " << b <<" with carry=" << carry << endl;

    int l=a.size();
    if (l==0) 
        return (carry==0)?"":"1";
    else
    {
        int alast=a[l-1]-'0';
        int blast=b[l-1]-'0';
        int last;
        cout << alast <<"+" << blast << "+" << carry << endl;
        if (alast+blast+carry>=2)
        {
            last=(alast+blast+carry)%2;
            carry=1;
        }
        else
        {
            last=(alast+blast+carry)%2;
            carry=0;
        }
        cout << "last=" << last << endl;
        return addBinary(a.substr(0,l-1),b.substr(0,l-1),carry)+to_string(last);
    }
}

int main()
{
    string a("11111");
    string b("11");
    cout << addBinary(a,b) << endl;
    return 0;
}
