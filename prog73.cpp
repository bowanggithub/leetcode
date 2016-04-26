#include <iostream>
#include <vector>
using namespace std;

void setZeros(vector<vector<int>>& matrix)
{
    if (matrix.size()==0 || matrix[0].size()==0)
        return;
    int m=matrix.size();
    int n=matrix[0].size();
    vector<bool> row(m,false);
    vector<bool> col(n,false);

    for (int r=0;r<m; r++)
    {
        for(int c=0;c<n;c++)
        {
            if (matrix[r][c]==0)
            {
                row[r]=true;
                col[c]=true;
            }
        }
    }

    for (int r=0; r<m;r++)
    {
        for (int c=0; c<n;c++)
        {
            if (row[r] || col[c])
                matrix[r][c]=0;
        }
    }
}

void printMatrix(vector<vector<int>>& matrix)
{
    for (auto vi:matrix)
    {
        for (auto x:vi)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix{{1,1,0},{0,1,1},{1,1,1}};
    printMatrix(matrix);
    cout << "-----------"<<endl;
    setZeros(matrix);
    printMatrix(matrix);
}

