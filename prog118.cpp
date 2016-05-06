#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    if (numRows<=0)
        return result;
    vector<int> row{1};
    result.push_back(row);
    for (int i=2; i<=numRows;i++)
    {
        vector<int> currRow={1};
        for (int j=0;j<row.size()-1;j++)
            currRow.push_back(row[j]+row[j+1]);
        currRow.push_back(1);
        result.push_back(currRow);
        row=currRow;
    }
    return result;
}

void printvvi(vector<vector<int>>& result)
{
    for (auto& vi:result)
    {
        for (int x:vi)
            cout << x << "\t";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> result=generate(9);
    printvvi(result);
}
