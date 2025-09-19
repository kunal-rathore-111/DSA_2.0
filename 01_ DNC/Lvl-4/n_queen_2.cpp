

// using unordered_map

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printBoard(int n, vector<vector<char>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// for left row
unordered_map<int, bool> leftRow; // it used to check kya is vali row par kahi bhi queen hae

// for bottom left
unordered_map<int, bool> bottomLeft; // it used to check kya is row+col pr kahi prr bhi queen hae

// for top left
unordered_map<int, bool> topLeft; // it used to check kya is col-row prr kahi prr bhi queen hae

bool isPossible(int row, int col, int n, vector<vector<char>> &board)
{
    if (leftRow[row])
        return false;

    if (bottomLeft[row + col])
        return false;

    if (topLeft[col - row])
        return false;

    return true;
}

void putQueen(int col, int n, vector<vector<char>> &board)
{
    // base Case
    if (col >= n)
    {
        printBoard(n, board);
        return;
    }

    // try to put every queen at every row
    for (int row = 0; row < n; row++)
    {
        // check is possible to put
        if (isPossible(row, col, n, board))
        {
            // then put and go for next queen using recursion

            // put queen and mark in maps
            board[row][col] = 'Q';

            leftRow[row] = true;
            bottomLeft[row + col] = true;
            topLeft[col - row] = true;

            // go for next
            putQueen(col + 1, n, board);

            // then backtrack and unmark from map
            board[row][col] = '-';

            leftRow[row] = false;
            bottomLeft[row + col] = false;
            topLeft[col - row] = false;
        }
    }
}

int main()
{

    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    putQueen(col, n, board);

    return 0;
}