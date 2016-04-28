#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    stack<int> stk;
    int i=0;
    int maxArea=0;
    vector<int> h(heights);
    h.push_back(0);
    while (i<h.size())
    {
        if (stk.empty() || h[stk.top()] <= h[i])
            stk.push(i++);
        else
        {
            int t=stk.top();
            stk.pop();
            maxArea = max(maxArea, h[t]*(stk.empty()?i:i-stk.top()-1));
        }
    }
    return maxArea;
}

int maxRectangle(vector<vector<int>>& matrix)
{
    if (matrix.size()==0 || matrix[0].size()==0)
        return 0;
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>> height(m,vector<int>(n+1,0));
    int maxArea=0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n;j++)
        {
            if (matrix[i][j]==0)
                height[i][j]=0;
            else
                height[i][j] = (i==0)?1:height[i-1][j]+1;
        }
    }

    for (int i=0; i<m;i++)
    {
        int area=largestRectangleArea(height[i]);
        maxArea=max(maxArea,area);
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> matrix{{0,0,1,0},{0,0,0,1},{0,1,1,1},{0,1,1,1}};
    cout << "max rectangle: " << maxRectangle(matrix) << endl;
}

