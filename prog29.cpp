#include <iostream>
using namespace std;

int divide(int dividend, int divisor)
{
    int result = 0;
    const bool sign = (dividend>0 && divisor<0) || (dividend<0 && divisor>0);
    unsigned int a = dividend >=0 ? dividend : -dividend;
    unsigned int b = divisor >=0 ? divisor : -divisor;

    while (a >= b)
    {
        int multi = 1;
        unsigned int bb =b;
        while (a >= bb)
        {
            a -= bb;
            result += multi;

            if (bb < INT_MAX >> 1)
            {
                bb += bb;
                multi +=multi;
            }
        }
    }
    if (sign) return -result;
    else return result;
}
