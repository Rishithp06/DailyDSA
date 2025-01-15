class Solution {
public:
    vector<vector<string>> partition(string s) {
        // This will store all the palindromic partitions
        vector<vector<string>> result;

        // Temporary vector to store the current partition
        vector<string> currentPartition;

        // Start the backtracking process from the first index of the string
        backtrack(s, 0, currentPartition, result);

        return result; // Return all the partitions
    }

private:
    // Backtracking function to explore all partitions
    void backtrack(const string& s, int index, vector<string>& currentPartition, vector<vector<string>>& result) {
        // Base Case: If the index has reached the end of the string
        if (index == s.size()) {
            // We have successfully partitioned the string, so add the current partition to the result
            result.push_back(currentPartition);
            return;
        }

        // Iterate over all possible substrings starting from 'index'
        for (int i = index; i < s.size(); i++) {
            // Check if the substring s[index:i+1] is a palindrome
            if (isPalindrome(s, index, i)) {
                // If it's a palindrome, include it in the current partition
                currentPartition.push_back(s.substr(index, i - index + 1));

                // Recur for the next part of the string starting from i + 1
                backtrack(s, i + 1, currentPartition, result);

                // Backtrack: Remove the last substring to explore other possibilities
                currentPartition.pop_back();
            }
        }
    }

    // Helper function to check if a substring s[left:right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        // Compare characters from both ends of the substring
        while (left < right) {
            if (s[left] != s[right]) {
                return false; // Not a palindrome if characters don't match
            }
            left++;
            right--;
        }
        return true; // The substring is a palindrome
    }
};
