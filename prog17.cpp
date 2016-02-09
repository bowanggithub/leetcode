//letter combinations of a phone number
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
void display(vector<string> svec)
{
    cout << "[ " ;
    for (int i=0; i< svec.size(); i++)
    {
        cout << svec[i] << " ";
    }
    cout << "]" << endl;
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
    //display(phone);

    int n=digits.size();
    vector<vector<string> > combinations(n,{""});
    //display(combinations[0]);
    for (int i=0; i<n; i++)
    {
        cout << "i=" << i << endl;
        display(combinations[i]);
        int m=digits[i]-'0';
        cout << "m=" << m << endl;
        for (int j=0; j<phone[m].size(); j++)
        {
            cout << "j=" << j << endl;
            for (int k=0; k<combinations[i].size(); k++)
            {
                cout << "k=" << k << endl;
                string s=combinations[i][k];
                cout << "s=" << s << endl;
                cout << "s+phone[m][j]=" << s+phone[m][j] << endl;
                combinations[i+1].push_back(s+phone[m][j]);
                display(combinations[i+1]);
            }
        }
    }
    return combinations[n-1];
}



int main()
{
    string digits="23";
    vector<string> combinations=letterCombinations(digits);
    display(combinations);
    //vector<vector<string> > combinations;
    //combinations.push_back({""});
    //display(combinations[0]);
    return 0;
}

