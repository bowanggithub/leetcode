#include <iostream>
#include <vector>
using namespace std;

void printmatrix(vector<vector<int>>& matrix)
{
    for (auto v:matrix)
    {
        for (auto x:v)
        {
            cout << x << "\t";
        }
        cout << endl;
    }
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int a, int b)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if (a==0 && b==1)
        return 1-obstacleGrid[m-2][n-1];
    else if (a==1 && b==0)
        return 1-obstacleGrid[m-1][n-2];
    else if (b==0)
        return (obstacleGrid[m-1][n-1-a])?0:
                uniquePathsWithObstacles(obstacleGrid,a-1,b);
    else if (a==0)
        return (obstacleGrid[m-1-b][n-1])?0:
                uniquePathsWithObstacles(obstacleGrid,a,b-1);
    else
    {
        return (obstacleGrid[m-1-b][n-1-a])?0:
                (uniquePathsWithObstacles(obstacleGrid,a-1,b)
                +uniquePathsWithObstacles(obstacleGrid,a,b-1));
    }
}

int main()
{
    vector<vector<int>> matrix(3,vector<int>(3,0));
    matrix[1][1]=1;
    printmatrix(matrix);
    cout << "num of paths: " << uniquePathsWithObstacles(matrix,2,2) << endl;
    return 0;
}
