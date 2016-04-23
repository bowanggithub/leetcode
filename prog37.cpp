#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

const int SodukuSize =9;
bool row_mask[SodukuSize][SodukuSize];
bool col_mask[SodukuSize][SodukuSize];
bool area_mask[SodukuSize][SodukuSize];

bool initSodukuMask(vector<vector<char>>& board)
{
    memset(row_mask,false,sizeof(row_mask));
    memset(col_mask,false,sizeof(row_mask));
    memset(area_mask,false,sizeof(row_mask));

    for (int r=0;r<board.size();r++)
    {
        for (int c=0;c<board[r].size();c++)
        {
            if (!isdigit(board[r][c]))
            {
                continue;
            }
            int idx=board[r][c]-'0'-1;

            int area=(r/3)*3+(c/3);
            if (row_mask[r][idx] || col_mask[c][idx] || area_mask[area][idx])
                return false;
            row_mask[r][idx] = col_mask[c][idx]=area_mask[area][idx] =true;
        }
    }
    return true;
}

void solveSoduku(vector<vector<char>>& board)
{
    if (board.size()<9 || board[0].size()<9) return;
    bool findSol = solSoduku(board,0,0);
}

bool solSoduku(vector<vector<char>>& board, int irow, int icol)
{
    if (irow==9) return true;
    int irow2,icol2;
    if (icol==8)
    {
        irow2=irow+1;
        icol2=0;
    }
    else
    {
        irow2=irow;
        icol2=icol+1;
    }

    if (board[irow][icol]!='.')
    {
        if (!isValid(board,irow,icol)) return false;
        return solSoduku(board,irow2,icol2);
    }
    for (int i=1;i<=9;i++)
    {
        board[irow][icol]='0'+i;
        if (isValid(board,irow,icol) && solSoduku(board,irow2,icol2)) return true;
    }
    board[irow][icol]='.';
    return false;
}

bool isValid(vector<vectorchar>>& board, int irow, int icol)
{
    char val=board[irow][icol];
    if (val-'0'<1 || val-'0'>9) return false;

    for (int i=0;i<9;i++)
    {
        if (board[irow][i]==val && i!= icol) return false;
        if (board[i][icol]==val && i!= irow) return false;
    }
    int irow0=irow/3*3;
    int icol0=icol/3*3;
    for (int i=irow0;i<irow0+3;i++)
    {
        for (int j=icol0;j<icol0+3;j++)
        {
            if (board[i][j] == val && (i!= irow || j!= icol))
                return false;
        }
    }
    return true;
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

