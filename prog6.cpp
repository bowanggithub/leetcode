//zigzag conversion
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(string text, int nRows)
{
    vector<string> r(nRows);
    int len=text.size();
    int row=0;
    int step=1;//going up or down
    for (int i=0; i<len;i++)
    {
        if (row==nRows-1)
            step=-1;
        else if (row == 0)
            step=1;

        r[row] += text[i];
        //cout << r[row] << endl;
        row += step;
    }
    string result;
    for (int i=0; i< nRows;i++)
    {
        result += r[i];
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
