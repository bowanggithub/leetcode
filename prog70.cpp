#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n<1) return 0;
    else if (n==1) return 1;
    else if (n==2) return 2;
    else
        return climbStairs(n-1)+climbStairs(n-2);
}

int main()
{
    for (int i=0;i<10;i++)
    {
        cout << climbStairs(i) << " ";
    }
    cout << endl;
}
