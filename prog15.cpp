//3 sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
    unordered_map<int,int> m;
    vector<vector<int> > result;
    for (int i=0; i<nums.size();i++)
    {
        if (m.find(nums[i]) == m.end())
        {
            m[nums[i]]=nums[i];
        }
    }

    for (int i=0; i<nums.size();i++)
    {
        for (int j=i+1; j<nums.size(); j++)
        {
            if (m.find(-nums[i]-nums[j]) != m.end() && (-nums[i]-nums[j]) >= nums[j])
            {
                vector<int> triplet={nums[i], nums[j], -nums[i]-nums[j]};
                result.push_back(triplet);
            }
        }
    }
    return result;
}

void display(vector<int> vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void display(vector<vector<int> > nums)
{
    for (int i=0; i<nums.size(); i++)
    {
        display(nums[i]);
    }
}

void sort(vector<int>& nums, int left, int right)
{
    int i=left, j=right;
    int tmp;
    int pivot = nums[(left+right)/2];

    while (i<=j)
    {
        while (nums[i] < pivot)
            i++;
        while (nums[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        sort(nums, left, j);
    if (i < right)
        sort(nums, i, right);
}

int main()
{
    vector<int> S={-1, 0, 1, 2, -1, -4};
    display(S);
    sort(S,0,S.size()-1);
    display(S);
    display(threeSum(S));
    return 0;
}
