#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int maxprofit=0;
    for (int i=0; i<prices.size()-1; i++)
    {
        maxprofit += max(prices[i+1]-prices[i],0);
    }

    return maxprofit;
}

int main()
{
    vector<int> prices{1,2,3,4,5,6,5,4,3,2,1,2,3,4,5,4,3,2,5,3,4,6,3,7,1};
    cout << "max profit is: " << maxProfit(prices) << endl;
}
