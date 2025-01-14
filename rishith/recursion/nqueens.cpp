class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results; // To store all valid board configurations
        vector<string> board(n, string(n, '.')); // Chessboard with empty cells
        vector<int> rowOccupied(n, 0); // Tracks if a queen exists in a row
        vector<int> lowerDiagonal(2 * n - 1, 0); // Tracks queens on lower diagonals
        vector<int> upperDiagonal(2 * n - 1, 0); // Tracks queens on upper diagonals

        placeQueens(0, n, board, rowOccupied, lowerDiagonal, upperDiagonal, results);
        return results;
    }

private:
    void placeQueens(int col, int n, vector<string>& board, vector<int>& rowOccupied, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, vector<vector<string>>& results) {
        // Base case: If all queens are placed
        if (col == n) {
            results.push_back(board); // Add the board configuration to the results
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; row++) {
            // Check if placing a queen at (row, col) is safe
            if (rowOccupied[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                // Place the queen
                board[row][col] = 'Q';
                rowOccupied[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to the next column
                placeQueens(col + 1, n, board, rowOccupied, lowerDiagonal, upperDiagonal, results);

                // Backtrack: Remove the queen and reset the state
                board[row][col] = '.';
                rowOccupied[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};
