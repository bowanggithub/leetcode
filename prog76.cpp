#include <iostream>
#include <string>
#include <map>
using namespace std;

bool allContains(map<char,int> m)
{
    for (auto iter=m.begin(); iter!= m.end();iter++)
    {
        if (iter->second >0)
            return false;
    }
    return true;
}

string minWindow(string S, string T)
{
    string result;
    if (S.size() <=0 || T.size()<=0 || T.size()> S.size())
        return result;

    map<char,int> m;
    for (auto x:T)
    {
        if (m.find(x)==m.end())
            m[x]=1;
        else
            m[x]++;
    }

    int shortstart=-1;
    int shortend=S.size()-1;
    int runningstart=0;
    int runningend=0;
    map<char,int> runningm(m);
    for (;runningend<S.size();runningend++)
    {
        runningm[S[runningend]]--;
        if (allContains(runningm))
        {
            for (;allContains(runningm);runningstart++)
            {
                runningm[S[runningstart]]++;
            }
            if (runningstart-runningend+1<shortend-shortstart)
            {
                shortend=runningend;
                shortstart=runningstart-1;
            }
        }
    }
    if (shortstart==-1)
        return result;
    else
        return S.substr(shortstart,shortend-shortstart+1);
}

int main()
{
    string S="AD0BEC0DEBANC";
    string T="ABD";
    cout << "min window: " << minWindow(S,T)<< endl;
}
