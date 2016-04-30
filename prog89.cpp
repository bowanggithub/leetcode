#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> result;
    for (int i=0; i<pow(2,n); i++)
    {
        int n=i^(i>>1);
        result.push_back(n);
    }
    return result;
}

int main()
{
    vector<int> result=grayCode(2);
    for (auto& x:result)
        cout << x << " ";
    cout << endl;
}

