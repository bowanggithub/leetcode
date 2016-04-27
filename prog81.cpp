#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> num, int low, int high, int value)
{
    if (high-low<4)
    {
        for (int i=low; i<=high; i++)
        {
            if (num[i]==value)
                return true;
        }
        return false;
    }

    int mid=(low+high)/2;
    if (num[low]<num[mid] && num[mid+1]<num[high])
    {
        if (num[low]<=value && value <= num[mid])
            return binarySearch(num,low,mid,value);
        else
            return binarySearch(num,mid+1,high,value);
    }
    else if (num[low]<num[mid] && num[mid+1]>num[high])
    {
        if (num[low]<=value && value <= num[mid])
            return binarySearch(num,low,mid,value);
        else
            return binarySearch(num,mid+1,high,value);
    }
    else if (num[low]>num[mid] && num[mid+1]<num[high])
    {
        if (num[mid+1]<=value && value <= num[high])
            return binarySearch(num,mid+1,high,value);
        else
            return binarySearch(num,low,mid,value);
    }
    else if (num[low]==num[mid] && num[mid+1] != num[high])
    {
        if (num[low]==value)
            return true;
        else
            return binarySearch(num, mid+1,high,value);
    }
    else if (num[low]!=num[mid] && num[mid+1] == num[high])
    {
        if (num[high]==value)
            return true;
        else
            return binarySearch(num, low, mid,value);
    }
    else
    {
        return binarySearch(num,low,mid,value) 
            || binarySearch(num,mid+1,high,value);
    }
}

int main()
{
    vector<int> num{3,3,3,3,4,5,6,3,3,3};
    cout << boolalpha << binarySearch(num,0,num.size()-1,3)<<endl;
    return 0;
}
