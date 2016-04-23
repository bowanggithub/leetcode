#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void nextPermutation(vector<int> &num)
{
    int pos=num.size()-1;
    while (num[pos] <= num[pos-1] && pos != 0)
    {
        pos--;
    }
    //cout << num[pos] << endl;
    if (pos==0)
        sort(num.begin(),num.end());
    else
    {
        int nextlarger=num.size()-1;
        for (;num[nextlarger]<=num[pos-1];nextlarger--);
        //cout << num[nextlarger] << endl;
        int tmp=num[pos-1];
        num[pos-1]=num[nextlarger];
        num[nextlarger]=tmp;
        sort(num.begin()+pos,num.end());
    }
}

string to_string(vector<int>& num)
{
    string s;
    for (auto x:num)
        s+=to_string(x);
    return s;
}

string getPermutation(int n, int k)
{
    vector<int> num;
    for (int i=1; i<=n; ++i)
        num.push_back(i);
    if (k==1) return to_string(num);    
    for (int i=1; i<k; ++i)
        nextPermutation(num);
    return to_string(num);
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << getPermutation(n,k);
}


