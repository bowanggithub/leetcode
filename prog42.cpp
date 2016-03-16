#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height)
{
    int n=height.size();
    if (n==0)
        return 0;
    int sum=0;
    int i,j,k;
    for (i=0;i<n-1 && height[i+1]>height[i];i++);
    if (i==n-1)
        return 0;
    for (j=i+1; j<n-1 && height[j+1]<height[j];j++);
    if (j==n-1)
        return 0;
    for (k=j+1; k<n-1 && height[k+1]>height[k];k++);
    cout << "i,j,k=: " << i << ", "<< j << ", " << k << endl;
    int minh=min(height[i],height[k]);
    for (int l=i; l<=k; l++)
        sum += max(0,minh-height[l]);
    cout << "sum= " << sum << endl;
    vector<int> subheight(height.begin()+k,height.end());
    return sum+trap(subheight);
}

int main()
{
    vector<int> h{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(h) << endl;
    return 0;
}

