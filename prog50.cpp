#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    if (n==0)
        return 1;
    else if (n<0)
        return 1/myPow(x,-n);
    else
    {
        double result=1.0;
        for (int i=0; i<n; i++)
        {
            result*= x;
        }
        return result;
    }
}

int main()
{
    cout << "enter x ,n: ";
    double x;
    int n;
    cin >> x >> n;
    cout << "power: " << myPow(x,n) << endl;
    return 0;
}
