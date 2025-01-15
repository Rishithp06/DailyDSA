#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findPath(vector<vector<int>>& maze, int n) {
        vector<string> paths; // To store all possible paths from start to end
        string currentPath = ""; // To track the current path being explored
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // To track visited cells

        // Start backtracking from the top-left corner if the cell is walkable (value == 1)
        if (maze[0][0] == 1) {
            backtrack(maze, n, 0, 0, visited, currentPath, paths);
        }

        return paths; // Return all found paths
    }

private:
    // Backtracking function to explore all valid paths
    void backtrack(vector<vector<int>>& maze, int n, int row, int col, vector<vector<bool>>& visited, string& currentPath, vector<string>& paths) {
        // Base case: If the rat reaches the bottom-right corner
        if (row == n - 1 && col == n - 1) {
            paths.push_back(currentPath); // Add the current valid path to the result
            return;
        }

        // Mark the current cell as visited to avoid cycles
        visited[row][col] = true;

        // Define possible moves: Down, Left, Right, Up
        vector<int> dRow = {1, 0, 0, -1}; // Row changes for D, L, R, U
        vector<int> dCol = {0, -1, 1, 0}; // Column changes for D, L, R, U
        string directions = "DLRU";       // Corresponding directions

        // Loop through all possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i]; // Calculate the new row
            int newCol = col + dCol[i]; // Calculate the new column

            // Check if the new cell is valid
            if (isValidMove(maze, n, newRow, newCol, visited)) {
                // Add the current direction to the path
                currentPath.push_back(directions[i]);

                // Recurse to explore the next cell
                backtrack(maze, n, newRow, newCol, visited, currentPath, paths);

                // Backtrack: Remove the last move after exploring
                currentPath.pop_back();
            }
        }

        // Unmark the current cell to allow other paths to use it
        visited[row][col] = false;
    }

    // Helper function to check if a cell is valid for movement
    bool isValidMove(vector<vector<int>>& maze, int n, int row, int col, vector<vector<bool>>& visited) {
        // Conditions:
        // 1. The cell must be within the grid boundaries.
        // 2. The cell value must be 1 (walkable).
        // 3. The cell must not have been visited in the current path.
        return row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && !visited[row][col];
    }
};

int main() {
    Solution solver;

    // Example maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Find all paths
    vector<string> paths = solver.findPath(maze, 4);

    // Print the results
    if (paths.empty()) {
        cout << "No paths found!" << endl;
    } else {
        cout << "All paths:" << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
