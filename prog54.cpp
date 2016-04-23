#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> v;
    if (matrix.size()<=0 || matrix[0].size()<=0)
        return v;
    int row=matrix.size();
    int col=matrix[0].size();
    int r,c;
    for (r=0,c=0;r<(matrix.size()+1)/2 && c<(matrix[0].size()+1)/2; r++,c++)
    {
        for (int i=c;i<col-c;i++)
            v.push_back(matrix[r][i]);
        for (int i=r+1;i<row-r;i++)
            v.push_back(matrix[i][col-c-1]);
        for (int i=col-c-2;i>=c;i--)
            v.push_back(matrix[row-r-1][i]);
        for (int i=row-r-2;i>r;i--)
            v.push_back(matrix[i][c]);
    }
    return v;
}

void printArray(vector<int>& v)
{
    for (auto x:v)
        cout << x << "\t";
    cout << endl;
}

void printMatrix(vector<vector<int>>& m)
{
    for (auto v:m)
        printArray(v);
}

int main()
{
    vector<vector<int>> m{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrix(m);
    cout << "--------------\n";
    auto v=spiralOrder(m);
    printArray(v);
    return 0;
}
