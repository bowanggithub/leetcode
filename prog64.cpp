#include <iostream>
#include <vector>
using namespace std;

inline int min(int a, int b)
{
    return (a>b)?b:a;
}

int minPathSum(vector<vector<int>>& grid, int a, int b)
{
    int m=grid.size();
    int n=grid[0].size();
    if (a<0 || b<0) 
        return 0;
    else if (a==0 && b==0)
        return grid[m-1][n-1];
    else if (a==0)
        return grid[m-1-b][n-1-a]+minPathSum(grid,a,b-1);
    else if (b==0)
        return grid[m-1-b][n-1-a]+minPathSum(grid,a-1,b);
    else
        return grid[m-1-b][n-1-a]+
                min(minPathSum(grid,a-1,b), minPathSum(grid,a,b-1));
}

int main()
{
    vector<vector<int>> a{{7,2},{6,6},{8,6},{5,0},{6,0}};
    cout << "min sum = " << minPathSum(a,a[0].size()-1,a.size()-1) << endl;
    return 0;
}
