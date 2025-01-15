class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(); // Number of rows
        int m = mat[0].size(); // Number of columns

        int left = 0;
        int high = m - 1;

        while (left <= high) {
            int mid = (left + high) / 2; // Middle column
            int maxrow = 0;

            // Find the row with the maximum value in the mid column
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxrow][mid]) {
                    maxrow = i;
                }
            }

            // Now check if it is a peak or not
            // Ensure boundary conditions are handled correctly
            if ((mid == 0 || mat[maxrow][mid] > mat[maxrow][mid - 1]) &&
                (mid == m - 1 || mat[maxrow][mid] > mat[maxrow][mid + 1])) {
                return {maxrow, mid};
            }

            // Move to the left or right half
            if (mid > 0 && mat[maxrow][mid - 1] > mat[maxrow][mid]) {
                high = mid - 1; // Move left
            } else {
                left = mid + 1; // Move right
            }
        }

        return {}; // Should not reach here for a valid input
    }
};
