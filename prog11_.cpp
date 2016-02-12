#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxArea(const vector<int>& heights)
{
    int maxArea=0;
    int n=heights.size();
    int l=0;
    int r=n-1;

    while (l<r)
    {
        maxArea=fmax(maxArea, (r-l)*fmin(heights[l],heights[r]));
        if (heights[l] < heights[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return maxArea;
}

int main()
{
    vector<int> heights={1,2,20,24,5,6};
    cout << "max area is: " << maxArea(heights) << endl;
    return 0;
}
