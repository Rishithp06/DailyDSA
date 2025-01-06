class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(); // Length of the input string
        string ans = "";    // To store the final result

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 2: Process each word in the reversed string
        for (int i = 0; i < n; i++) {
            string word = ""; // Temporary variable to store the current word

            // Step 3: Extract a word from the string
            while (i < n && s[i] != ' ') {
                word += s[i]; // Append characters until a space is encountered
                i++;
            }

            // Step 4: Reverse the word to restore its original order
            reverse(word.begin(), word.end());

            // Step 5: Add the word to the result if it's not empty
            if (word.length() > 0) {
                ans += " " + word; // Add a space before each word
            }
        }

        // Step 6: Remove the leading space from the result
        return ans.substr(1);
    }
};
