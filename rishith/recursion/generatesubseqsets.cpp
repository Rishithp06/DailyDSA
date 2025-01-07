class Solution {
public:
    // Helper function for recursion
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we reach the end of the array
        if (index == nums.size()) {
            result.push_back(current); // Add the current subset to the result
            return;
        }

        // Recursive case 1: Include the current element
        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, result);
        current.pop_back(); // Backtrack to explore the next option

        // Recursive case 2: Exclude the current element
        generateSubsets(nums, index + 1, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // To store all subsets
        vector<int> current; // To store the current subset
        generateSubsets(nums, 0, current, result); // Start recursion
        return result; // Return all subsets
    }
};
