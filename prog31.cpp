#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
    vector<int> num{1,3,2,1};
    for (auto x : num)
        cout << x << ", ";
    cout << endl;
    for (int i=0; i<10;i++)
    {
        nextPermutation(num);
        for (auto x : num)
            cout << x << ", ";
        cout << endl;
    }
    return 0;
}
