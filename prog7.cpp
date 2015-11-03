//reverse integer
#include <iostream>
using namespace std;

int reverse(int x)
{
    if (x > 0)
    {
        int y=0;
        int n=x%10;
        while (x != 0)
        {
            y = 10*y+n;
            x /= 10;
            n = x%10;
        }
        return y;
    }
    else
        return -reverse(-x);
}

int main()
{
    //int x=123;
    //cout << x << " : " << reverse(x) << endl;
    //cout << -x << " : " << reverse(-x) << endl; 
    int x;
    cout << "enter number: ";
    while (cin >> x)
    {
        cout << x << " : " << reverse(x) << endl;
    }
    return 0;
}

