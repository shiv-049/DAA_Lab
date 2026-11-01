
#include <iostream>
using namespace std;

#define N 4

int board[N][N] = {0};

// Check whether queen can be placed safely
bool isSafe(int row, int col)
{
    // Check same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve N-Queen using backtracking
bool solveNQueen(int row)
{
    // All queens are placed
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueen(row + 1))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

// Display chessboard
void printBoard()
{
    cout << "\nSolution:\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    if (solveNQueen(0))
    {
        cout << "N-Queen solution exists!";
        printBoard();
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
