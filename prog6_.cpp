#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string text, int nRows)
{
    vector<string> r(nRows);
    int len=text.size();
    int row=0;
    int step=1;
    for (int i=0;i<len;i++)
    {
        r[row] += text[i];

        if (row==0)
            step=1;
        else if (row==nRows-1)
            step=-1;

        row += step;
    }
    string result;
    for (int i=0; i<nRows;i++)
    {
        result += r[i];
        cout << r[i] << endl;
    }
    return result;
}

int main()
{
    string s="PAYPALISHIRING";
    int r=3;
    cout << s << " : " << convert(s,r) << endl;
    return 0;
}
