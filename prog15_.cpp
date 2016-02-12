#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
        if (i<=j)
        {
            tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
            i++;
            j--;
        }
    }

    if (left <j)
        sort(nums,left,j);
    if (i < right)
        sort(nums,i,right);
}

void display(vector<int> vec)
{
    cout << "(";
    for (int i=0;i<vec.size()-1;i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size()-1] << ")" << endl;
}

void display(vector<vector<int> > vecs)
{
    for (int i=0;i<vecs.size();i++)
        display(vecs[i]);
}

vector<vector<int> > threeSum(const vector<int>& nums)
{
    vector<vector<int> > answers;
    for (int i=0;i<nums.size()-2;i++)
    {
        int target=-nums[i];
        //cout << "target: " << target << endl;
        unordered_map<int,int> m;
        for (int j=i+1;j<nums.size();j++)
        {
            if (m.find(nums[j]) == m.end())
                m[target-nums[j]] = nums[j];
            else
            {
                vector<int> ans;
                ans.push_back(-target);
                ans.push_back(m[nums[j]]);
                ans.push_back(nums[j]);
                //display(ans);
                answers.push_back(ans);
            }
        }
    }
    return answers;
}


int main()
{
    vector<int> S={-1,0,1,2,-1,-4};
    display(S);
    sort(S,0,S.size()-1);
    display(S);
    cout << endl;
    //threeSum(S);
    display(threeSum(S));
    return 0;
}

