#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(const vector<string>& svec)
{
    cout << "[";
    for (int i=0;i<svec.size()-1;i++)
    {
        cout << svec[i] << " ";
    }
    cout << svec[svec.size()-1] << "]" << endl;
}

vector<string> letterCombinations(string digits)
{
    vector<string> phone;
    phone.push_back("");
    phone.push_back("");
    phone.push_back("abc");
    phone.push_back("def");
    phone.push_back("ghi");
    phone.push_back("jkl");
    phone.push_back("mno");
    phone.push_back("pqrs");
    phone.push_back("tuv");
    phone.push_back("wxyz");

    int n=digits.size();
    if (n==0)
    {
        vector<string> comb={""};
        return comb;
    }

    string subdigits=digits.substr(1,digits.size()-1);
    vector<string> subcomb=letterCombinations(subdigits);
    int m=digits[0]-'0';
    vector<string> comb;
    for (int i=0;i<phone[m].size();i++)
    {
        for (int j=0;j<subcomb.size();j++)
        {
            string newcomb = phone[m][i] + subcomb[j];
            comb.push_back(newcomb);
        }
    }
    return comb;
}

int main()
{
    string digits="235";
    vector<string> combinations=letterCombinations(digits);
    display(combinations);
    return 0;
}

