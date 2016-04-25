#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int l=digits.size()-1;
    int carry=1;
    for (;l>0;l--)
    {
        int ones=(digits[l]+carry)%10;
        int tens=(digits[l]+carry)/10;
        carry=tens;
        digits[l]=ones;
    }
    int ones=(digits[l]+carry)%10;
    int tens=(digits[l]+carry)/10;
    carry=tens;
    digits[l]=ones;
    if (carry !=0)
        digits.insert(digits.begin(),carry);
    return digits;
}

void printVi(vector<int>& vi)
{
    for (auto x:vi)
        cout <<x;
    cout << endl;
}

int main()
{
    vector<int> digits{1,2,3,4,5,7,8,9,9,9};
    printVi(digits);
    vector<int> newdigits=plusOne(digits);
    printVi(newdigits);
    return 0;
}



