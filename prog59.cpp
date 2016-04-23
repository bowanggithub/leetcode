#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix)
{
    for (auto row:matrix)
    {
        for (auto num:row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

vector<vector<int>> generateMatrix(int n)
{
    int num_to_insert=1;
    vector<int> vi(n,0);
    vector<vector<int>> result(n,vi);
    printMatrix(result);
    int r,c;
    for (r=0, c=0; r<(n)/2 && c<(n)/2; r++,c++)
    {
        for (int i=c; i<=n-2-c;++i)
        {
            result[r][i]=num_to_insert;
            num_to_insert++;
        }
        printMatrix(result);
        for (int i=r;i<=n-2-r;++i)
        {
            result[i][n-1-c]=num_to_insert;
            num_to_insert++;
        }
        printMatrix(result);
        for (int i=n-1-c; i>=c+1; --i)
        {
            result[n-r-1][i]=num_to_insert;
            num_to_insert++;
        }
        printMatrix(result);
        for (int i=n-1-r; i>=r+1; --i)
        {
            result[i][c]=num_to_insert;
            num_to_insert++;
        }
        printMatrix(result);
    }
    if (n%2==1) result[r][c]=num_to_insert;
    return result;
}

int main()
{
    auto matrix=generateMatrix(5);
    printMatrix(matrix);
    return 0;
}
