#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min(int x, int y)
{
    return (x>y)?y:x;
}

int min(int x, int y, int z)
{
    return (min(x,y)>z)?z:min(x,y);
}

int minDistance(string word1, string word2)
{
    int m=word1.size();
    int n=word2.size();
    if (m==0) return n;
    else if (n==0) return m;

    vector<vector<int>> matrix(m+1, vector<int>(n+1));
    for (int i=1; i<=m; i++)
        matrix[i][0]=i;
    for (int i=1; i<=n; i++)
        matrix[0][i]=i;

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (word1[i-1]==word2[j-1])
                matrix[i][j]=matrix[i-1][j-1];
            else
                matrix[i][j]=1+min(matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]);
        }
    }
    return matrix[m][n];
}

int main()
{
    string a="abb";
    string b="abccb";
    cout << minDistance(a,b) << endl;
}
