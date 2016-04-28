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

int main()
{
    vector<int> heights{2,1,5,6,2,3};
    cout << "max area: " << largestRectangleArea(heights)<< endl;
}

