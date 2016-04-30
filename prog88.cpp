#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, vector<int>& nums2)
{
    auto p1=nums1.begin();
    auto p2=nums2.begin();
    for (;p1!=nums1.end() && p2!=nums2.end();)
    {
        if (*p1 <= *p2)
            p1++;
        else
        {
            p1=nums1.insert(p1,*p2);
            p1++;
            p2++;
        }
    }

    while (p2!=nums2.end())
    {
        nums1.push_back(*p2);
        p2++;
    }
}

int main()
{
    vector<int> a1{1,3,5,7,9};
    vector<int> a2{2,4,6,8,10,12,14};
    merge(a1,a2);
    for (auto& x : a1)
        cout << x << " ";
    cout << endl;
}
