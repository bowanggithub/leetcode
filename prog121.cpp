#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int max=0, begin=0, end=0, delta=0;

    for (int i=0; i<prices.size();i++)
    {
        delta=prices[end]-prices[begin];
        
        if (delta >0)
        {
            end++;
        }
        else
        {
            begin=end;
            end++;
        }

        max=(max<delta)?delta:max;
    }

    return max;
}

int main()
{
    vector<int> prices{1,2,3,4,1,0,2,5,7,0,0,2,4};
    cout << "max profit is: " << maxProfit(prices) << endl;
}
