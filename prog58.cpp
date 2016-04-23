#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int lengthOfLastWord(string s)
{
    int cnt=0;
    int wordLength=0;
    if (s.size()<=0) return wordLength;
    for (auto x:s)
    {
        if (isalpha(x))
        {
            cnt++;
        }
        else
        {
            wordLength=cnt;
            cnt=0;
        }
    }
    wordLength=cnt;
    return wordLength;
}

int main()
{
    string s{"hello world"};
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
