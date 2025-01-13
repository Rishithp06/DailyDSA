class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(); // Number of rows in the grid
        int cols = board[0].size(); // Number of columns in the grid

        // Iterate over each cell in the grid as the starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If the first character matches, start a DFS from here
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true; // If DFS finds the word, return true
                }
            }
        }

        return false; // If no path matches the word, return false
    }

private:
    // DFS function to explore the grid
    bool dfs(vector<vector<char>>& board, const string& word, int index, int row, int col) {
        // Base case: If the entire word is matched
        if (index == word.size()) return true;

        // Check boundary conditions and if the cell matches the current character
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        // Temporarily mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '*';

        // Explore all four possible directions (up, down, left, right)
        bool found = dfs(board, word, index + 1, row + 1, col) || // Down
                     dfs(board, word, index + 1, row - 1, col) || // Up
                     dfs(board, word, index + 1, row, col + 1) || // Right
                     dfs(board, word, index + 1, row, col - 1);   // Left

        // Backtrack by resetting the cell
        board[row][col] = temp;

        return found; // Return true if any path found the word
    }
};
