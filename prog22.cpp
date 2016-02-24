#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> generator(int left, int right)
{
    vector<string> results;
    if (right > left)
        return results;
    else if (right == 0)
    {
        string s(left,'(');
        results.push_back(s);
    }
    else
    {
        vector<string> subresults1 = generator(left-1,right);
        for (auto x : subresults1)
        {
            results.push_back(x+"(");
        }
        vector<string> subresults2 = generator(left,right-1);
        for (auto x : subresults2)
        {
            results.push_back(x+")");
        }
    }
    return results;
}

void display(vector<string> results)
{
    for (auto x : results)
        cout << x << endl;
}

int main()
{
    vector<string> results = generator(4,4);
    display(results);
    return 0;
}

