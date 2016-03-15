#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool checkrow(vector<vector<char>>& board)
{
    for (int i=0; i<9; i++)
    {
        map<char, int> m;
        for (int j=0; j<9;j++)
        {
            if (m.find(board[i][j]) == m.end())
                m[board[i][j]]=1;
            else
                m[board[i][j]]++;
        }
        for (auto iter=m.begin();iter!=m.end();iter++)
        {
            if (isdigit(iter->first) && iter->second>1)
                return false;
        }
    }
    return true;
}

bool checkcolumn(vector<vector<char>>& board)
{
    for (int i=0; i<9; i++)
    {
        map<char, int> m;
        for (int j=0; j<9;j++)
        {
            if (m.find(board[i][j]) == m.end())
                m[board[j][i]]=1;
            else
                m[board[j][i]]++;
        }
        for (auto iter=m.begin();iter!=m.end();iter++)
        {
            if (isdigit(iter->first) && iter->second>1)
                return false;
        }
    }
    return true;
}

bool checkblock(vector<vector<char>>& board)
{
    for (int bi=0;bi<3;bi++)
    {
        for (int bj=0;bj<3;bj++)
        {
            map<char,int> m;
            for (int i=3*bi;i<3*bi+3;i++)
            {
                for (int j=3*bj;j<3*bj+3;j++)
                {
                    if (m.find(board[i][j]) == m.end())
                        m[board[i][j]]=1;
                    else
                        m[board[i][j]]++;
                }
            }
            for (auto iter=m.begin();iter!=m.end();iter++)
            {
                if (isdigit(iter->first) && iter->second>1)
                    return false;
            }
        }
    }
    return true;
}



bool isValidSudoku(vector<vector<char>>& board)
{
    if (checkrow(board) && checkcolumn(board) && checkblock(board))
        return true;
    else
        return false;
}

int main()
{
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','8','.','.','7','9'}};
    cout << boolalpha << isValidSudoku(board) << endl;
    return 0;
}

