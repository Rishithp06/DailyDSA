class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Helper function for backtracking
        generateUniqueSubsets(nums, current, 0, result);
        
        return result;
    }
    
private:
    void generateUniqueSubsets(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Iterate through the array
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include the current element
            current.push_back(nums[i]);
            
            // Recurse for the next element
            generateUniqueSubsets(nums, current, i + 1, result);
            
            // Backtrack by removing the last element
            current.pop_back();
        }
    }
};
