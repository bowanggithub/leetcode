#include <iostream>
#include <cmath>
using namespace std;

long double square_root(int x)
{
    long double guess=10;
    long double last=0;
    while (abs(guess-last)>1e-5)
    {
        last=guess;
        guess=guess-(guess*guess-x)/(2*guess);
    }
    return guess;
}

int main()
{
    int x=612;
    cout << "sqrt=" << square_root(x) << endl;
    return 0;
}

