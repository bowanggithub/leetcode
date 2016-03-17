#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int factorial(int x)
{
    return (x==1 ? x : x*factorial(x-1));
}

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

vector<vector<int>> permutations(vector<int>& num)
{
    vector<vector<int>> results;
    for (int i=0; i<factorial(num.size()); i++)
    {
        results.push_back(num);
        nextPermutation(num);
    }
    return results;
}

int main()
{
    vector<int> num{1,2,3,4};
    vector<vector<int>> results = permutations(num);
    for (auto x : results)
    {
        for (auto y : x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }

    return 0;
}
