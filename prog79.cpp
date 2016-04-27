#include <iostream>
#include <vector>
using namespace std;

bool exist(vector<vector<char>>& board, string word, int r, int c,
            vector<vector<bool>>& used)
{
    if (word.size()==0) return true;
    else if (word[0] != board[r][c] || used[r][c])
        return false;
    else
    {
        used[r][c]=true;
        string subword=word.substr(1,word.size()-1);
        return ((r>0                 && exist(board,subword,r-1,c,used)) ||
            (r<board.size()-1    && exist(board,subword,r+1,c,used)) ||
            (c>0                 && exist(board,subword,r,c-1,used)) ||
            (c<board[0].size()-1 && exist(board,subword,r,c+1,used)) );
    }
}

bool exist(vector<vector<char>>& board, string word)
{
    for (int i=0; i<board.size();i++)
    {
        for (int j=0; j<board[0].size(); j++)
        {
            vector<vector<char>> boardcopy(board);
            vector<vector<bool>> used{3,vector<bool>(3,false)};
            if (exist(board,word,i,j,used))
                return true;
        }
    }
    return false;
}


int main()
{
    vector<vector<char>> board{{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    //vector<vector<bool>> used{3,vector<bool>(3,false)};
    cout << boolalpha << exist(board,"SEE") << endl;
}


        
