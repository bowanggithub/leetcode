#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& A)
{
    int n=A.size();
    if (n<=1)
        return n;

    int pos=0;
    for (int i=0; i<n; i++)
    {
        if (A[i] != A[pos])
        {
            pos++;
            A[pos]=A[i];
        }
    }
    return pos+1;
}

int main()
{
    vector<int> A={1,1,2,2,2,2,2,3,4,4,5,5,5,5,6};
    int n=removeDuplicates(A);
    cout << "n= " << n << endl;
    for (int i=0;i<n;i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
