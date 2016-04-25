#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    if (m<0 || n<0)
        return 0;
    else if (m==0)
        return 1;
    else if (n==0)
        return 1;
    else
        return uniquePaths(m-1,n)+uniquePaths(m,n-1);
}

int main()
{
    cout << "3,5: " << uniquePaths(3,5) << endl;
    return 0;
}

