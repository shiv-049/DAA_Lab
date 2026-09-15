#include <iostream>
using namespace std;

int n;
int board[20][20];

// Check whether a queen can be placed
bool safe(int row, int col)
{
    // Check same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }

    // Check left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Solve N-Queens problem
bool solve(int row)
{
    // All queens are placed
    if (row == n)
        return true;

    // Try every column in the current row
    for (int col = 0; col < n; col++)
    {
        if (safe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Move to next row
            if (solve(row + 1))
                return true;

            // Remove queen if solution is not possible
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter n: ";
    cin >> n;

    if (solve(0))
    {
        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution";
    }

    return 0;
}
