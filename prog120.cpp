#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle, int r, int c)
{
    int n=triangle.size();
    if (r==n-1)
        return triangle[r][c];
    else
        return triangle[r][c]+
            min(minimumTotal(triangle,r+1,c),minimumTotal(triangle,r+1,c+1));
}

int main()
{
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle,0,0) << endl;
}
