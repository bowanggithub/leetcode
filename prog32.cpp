#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch=='{' || ch=='[' || ch=='(')
        {
            st.push(ch);
        }
        else if (ch=='}' || ch==']' || ch==')')
        {
            if (st.empty()) return false;
            char sch=st.top();
            if ((sch=='{' && ch=='}') || (sch=='[' && ch==']') 
                    || (sch=='(' && ch==')'))
                st.pop();
            else return false;
        }
        else return false;
    }
    return st.empty();
}

int longestValidParentheses(string s)
{
    int length=0;
    int pos=0;
    for (int i=0;i<s.size();i++)
    {
        for (int j=0;j<s.size()-i;j++)
        {
            if (isValid(s.substr(i,j)) && s.substr(i,j).size()>length)
            {
                length=s.substr(i,j).size();
                pos=i;
            }
        }
    }
    cout << "position at " << pos << endl;
    return length;
}

int main(int argc, char** argv)
{
    string s="{{}{[]()}}";
    if (argc > 1)
    {
        s=argv[1];
    }
    cout << s << " : " << longestValidParentheses(s) << endl;
    return 0;
}

