#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of a string
void generateSubsets(string& input, vector<char>& current, int index, vector<vector<char>>& result) {
    if (index == input.length()) {
        result.push_back(current); // Add current subset to the result
        return;
    }

    // Include the current character
    current.push_back(input[index]);
    generateSubsets(input, current, index + 1, result);

    // Exclude the current character
    current.pop_back(); // Backtracking step
    generateSubsets(input, current, index + 1, result);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    vector<vector<char>> subsets; // To store all subsets
    vector<char> current; // Temporary vector for each subset

    generateSubsets(input, current, 0, subsets);

    // Display all subsets
    cout << "All subsets of the string \"" << input << "\":" << endl;
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (char c : subset) {
            cout << c << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
