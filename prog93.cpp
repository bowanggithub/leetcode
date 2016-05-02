#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string s, int n)
{
    if (n==1)
        return (stoi(s)<=255 && stoi(s)>=0);
    else
    {
        return (s.size()>=1 && isValid(s.substr(1,s.size()-1),n-1) ||
                s.size()>=2 && isValid(s.substr(2,s.size()-2),n-1) ||
                s.size()>=3 && isValid(s.substr(0,3),1) 
                            && isValid(s.substr(3,s.size()-3),n-1));
    }
}

void IpAddresses(string s, int n, string Ip, vector<string>& result)
{
    if (n==1 && isValid(s,1))
    {
        Ip+=s;
        //cout << "one possible: " << Ip << endl;
        result.push_back(Ip);
    }

    for (int i=3; i>=1;i--)
    {
        if (s.size()>=i && isValid(s.substr(0,i),1) 
                        && isValid(s.substr(i,s.size()-i),n-1))
        {
            string newIp= Ip+s.substr(0,i)+".";
            //cout<<newIp<<" : "<< s.substr(i,s.size()-i) << " : " << n-1 << endl;
            IpAddresses(s.substr(i,s.size()-i),n-1,newIp,result);
        }
        /*
        if (s.size()>=3 && isValid(s.substr(0,3),1) 
                        && isValid(s.substr(3,s.size()-3),n-1))
        {
            Ip= Ip+s.substr(0,3)+".";
            cout << Ip << " : " << s.substr(3,s.size()-3) << " : " << n-1 << endl;
            return IpAddresses(s.substr(3,s.size()-3),n-1,Ip,result);
        }
        if (s.size()>=2 && isValid(s.substr(2,s.size()-2),n-1))
        {
            Ip= Ip+s.substr(0,2)+".";
            cout << Ip << " : " << s.substr(2,s.size()-2) << " : " << n-1 << endl;
            return IpAddresses(s.substr(2,s.size()-2),n-1,Ip,result);
        }
        if (s.size()>=1 && isValid(s.substr(1,s.size()-1),n-1))
        {
            Ip= Ip+s.substr(0,1)+".";
            cout << Ip << " : " << s.substr(1,s.size()-1) << " : " << n-1 << endl;
            return IpAddresses(s.substr(1,s.size()-1),n-1,Ip,result);
        }
        */
    }
}

vector<string> restoreIpAddresses(string s)
{
    string Ip;
    vector<string> result;
    IpAddresses(s,4,Ip,result);
    //cout << result.size() << endl;
    return result;
}

int main()
{
    string s="2525511135";
    vector<string> vs=restoreIpAddresses(s);
    for (auto& x:vs)
        cout << x << endl;
    return 0;
}


