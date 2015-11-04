//container with most water
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int maxArea(vector<int>& height)
{
    int n=height.size();
    int maxArea=0;
    int left=0;
    int right=n-1;

    while (left < right)
    {
        maxArea=fmax(maxArea, (right-left)*fmin(height[left],height[right]));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}

int main()
{
    vector<int> height={1,2,3,4,5,6};
    cout << "the max area is " << maxArea(height) << endl;
    return 0;
}
