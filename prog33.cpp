#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> num, int low, int high, int value)
{
    if (high-low<4)
    {
        for (int i=low; i<=high; i++)
        {
            if (num[i]==value)
                return i;
        }
        return -1;
    }

    int mid=(low+high)/2;
    if (num[low]<num[mid] && num[mid+1]<num[high])
    {
        if (num[low]<=value && value <= num[mid])
            return binarySearch(num,low,mid,value);
        else
            return binarySearch(num,mid+1,high,value);
    }
    else if (num[low]<num[mid])
    {
        if (num[low]<=value && value <= num[mid])
            return binarySearch(num,low,mid,value);
        else
            return binarySearch(num,mid+1,high,value);
    }
    else
    {
        if (num[mid+1]<=value && value <= num[high])
            return binarySearch(num,mid+1,high,value);
        else
            return binarySearch(num,low,mid,value);
    }
}

int main()
{
    vector<int> num{4,5,6,7,0,1,2};
    cout << binarySearch(num,0,num.size(),6)<<endl;
    return 0;
}
