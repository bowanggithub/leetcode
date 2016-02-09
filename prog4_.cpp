#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double findKSortedArrays(vector<int>& nums1, vector<int>& nums2, int k)
{
    int l1=nums1.size();
    int l2=nums2.size();

    if (l1 >l2)
        nums1.swap(nums2);
    l1=nums1.size();
    l2=nums2.size();

    int k1=(fmin(l1,k)-1)/2;
    int k2=k-k1-2;

    if (l1 == 0)
    {
        return nums2[k-1];
    }
    else if (l2 == 0)
    {
        return nums1[k-1];
    }
    else if (k == 1)
    {
        return fmin(nums1[0],nums2[0]);
    }
    else if (nums1[k1] == nums2[k2])
    {
        return nums1[k1];
    }
    else if (nums1[k1] > nums2[k2])
    {
        vector<int> subnums1(nums1.begin(),nums1.begin()+k1+1);
        vector<int> subnums2(nums2.begin()+k2+1,nums2.end());
        return findKSortedArrays(subnums1,subnums2,k-k2-1);
    }
    else
    {
        vector<int> subnums2(nums2.begin(),nums2.begin()+k2+1);
        vector<int> subnums1(nums1.begin()+k1+1,nums1.end());
        return findKSortedArrays(subnums1,subnums2,k-k1-1);
    }
}

double findMedianSortedArray(vector<int>& nums1, vector<int>& nums2)
{
    if ((nums1.size()+nums2.size())%2 ==1)
    {
        int k=(nums1.size()+nums2.size()+1)/2;
        return findKSortedArrays(nums1,nums2,k);
    }
    else
    {
        int k=(nums1.size()+nums2.size())/2;
        return ( findKSortedArrays(nums1,nums2,k)+
                findKSortedArrays(nums1,nums2,k+1) )/2.0;
    }
}

int main()
{
    vector<int> nums1 = {1,12,15,26,38,50};
    vector<int> nums2 = {2,13,17,30,45};
    cout << "median is: " << findMedianSortedArray(nums1,nums2) << endl;
    return 0;
}
