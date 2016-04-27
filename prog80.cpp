#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates2(vector<int>& A)
{
    int n=A.size();
    if (n<=1)
        return n;

    int pos=0;
    int cnt=1;
    for (int i=0; i<n; i++)
    {
        if (A[i] != A[pos])
        {
            pos++;
            A[pos]=A[i];
            cnt=1;
        }
        else if (A[i] == A[pos] && cnt==1)
        {
            pos++;
            A[pos]=A[i];
            cnt=2;
        }
        else
        {
            continue;
        }
    }
    return pos+1;
}

int main()
{
    vector<int> A{1,1,1,2,2,2,2,2,2,2,3,4,4,4,5,6,6,6,6,6,6};
    int n=removeDuplicates2(A);
    cout << "n= " << n << endl;
    for (int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}
