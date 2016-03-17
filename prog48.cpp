#include <iostream>
#include <vector>
using namespace std;

void show(vector<vector<int>>& matrix)
{
    for (auto x : matrix)
    {
        for (auto y : x)
        {
            cout << y << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    if (n%2==0)
    {
        for (int i=0; i<n/2; i++)
        {
            for (int j=0; j<n/2; j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                show(matrix);
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                show(matrix);
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                show(matrix);
                matrix[j][n-1-i]=temp;
                show(matrix);
            }
        }
    }
    else
    {
        for (int i=0; i<n/2; i++)
        {
            for (int j=0; j<n/2+1; j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    show(matrix);
    rotate(matrix);
    cout << endl;
    show(matrix);
    return 0;
}
