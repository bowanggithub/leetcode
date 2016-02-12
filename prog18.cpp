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
    if (left < j)
        sort(nums,left,j);
    if (i < right)
        sort(nums,i,right);
}

void display(const vector<int> vec)
{
    cout << "(";
    for (int i=0;i<vec.size()-1;i++)
        cout << vec[i] << ", ";
    cout << vec[vec.size()-1] << ")" << endl;
}

void display(const vector<vector<int> > vecs)
{
    for (int i=0;i<vecs.size();i++)
        display(vecs[i]);
}

vector<vector<int> > threeSum(const vector<int>& nums, int tar)
{
    vector<vector<int> > answers;
    for (int i=0;i<nums.size()-2;i++)
    {
        int target=tar-nums[i];
        unordered_map<int,int> m;
        for (int j=i+1;j<nums.size();j++)
        {
            if (m.find(nums[j]) == m.end())
                m[target-nums[j]] = nums[j];
            else
            {
                vector<int> ans;
                ans.push_back(nums[i]);
                ans.push_back(m[nums[j]]);
                ans.push_back(nums[j]);
                answers.push_back(ans);
            }
        }
    }
    return answers;
}

vector<vector<int> > fourSum(const vector<int>& nums)
{
    vector<vector<int> > answers4;
    for (int i=0;i<nums.size()-3;i++)
    {
        vector<int> subnums(nums.begin()+i+1,nums.end());
        vector<vector<int> > answers3=threeSum(subnums,-nums[i]);
        for (int j=0;j<answers3.size();j++)
        {
            vector<int> ans3=answers3[j];
            vector<int> ans4;
            ans4.push_back(nums[i]);
            ans4.push_back(ans3[0]);
            ans4.push_back(ans3[1]);
            ans4.push_back(ans3[2]);
            answers4.push_back(ans4);
        }
    }
    return answers4;
}

int main()
{
    vector<int> a={1,0,-1,0,-2,2};
    sort(a,0,a.size()-1);
    display(a);
    vector<vector<int> > answers4=fourSum(a);
    display(answers4);
    return 0;
}
