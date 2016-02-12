#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

string intToRoman(int num)
{
    string roman;
    vector<string> symbol={"M","CM","D","CD","C","XC","L","XL",
                            "X","IX","V","IV","I"};
    vector<int> value={1000,900,500,400,100,90,50,40,10,9,5,4,1};

    for (int i=0;i<value.size();i++)
    {
        while (num >= value[i])
        {
            num -= value[i];
            roman += symbol[i];
        }
    }
    return roman;
}

int main(int argc, char** argv)
{
    int num=1234;
    if (argc >1)
        num= atoi(argv[1]);

    cout << num << " : " << intToRoman(num) << endl;
    return 0;
}
