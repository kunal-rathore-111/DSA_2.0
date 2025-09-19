
// using while loops

#include <iostream>
#include <vector>

using namespace std;

void printFunc(vector<vector<char>> &board, int n)
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPossible(int row, int col, vector<vector<char>> &board, int n)
{

    int i = row, j = col;

    // for row's left
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    j = col;

    // for upper left
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;

    // bottom left
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void placeQueens(int col, vector<vector<char>> &board, int n)
{
    // base case
    if (col >= n)
    {
        printFunc(board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        // check, if possible put and go ahead else, backtrack to previous one
        // check

        if (isPossible(row, col, board, n))
        {

            // put
            board[row][col] = 'Q';

            // recursion (for go ahead)
            placeQueens(col + 1, board, n);

            // backtrack
            board[row][col] = '-';
        }
    }
}

int main()
{

    int n = 4;

    // board
    vector<vector<char>> board(n, vector<char>(n, '-'));

    // starting col
    int col = 0;

    placeQueens(col, board, n);

    return 0;
}