#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find a subsequence with sum k
bool findSubsequence(int index, vector<int>& arr, vector<int>& subsequence, int currentSum, int targetSum) {
    // Base case: If the sum matches the target
    if (currentSum == targetSum) {
        return true;
    }

    // Base case: If we've reached the end of the array
    if (index == arr.size()) {
        return false;
    }
    //subsequence is an array which will store all elements with target sum
    // Include the current element in the subsequence
    subsequence.push_back(arr[index]);
    if (findSubsequence(index + 1, arr, subsequence, currentSum + arr[index], targetSum)) {
        return true;
    }
    // Backtrack: Exclude the current element and move on to next and try adding that to array subsequence and check it once
    subsequence.pop_back();
    if (findSubsequence(index + 1, arr, subsequence, currentSum, targetSum)) {
        return true;
    }

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Input array
    int targetSum = 6;                // Target sum
    vector<int> subsequence;

    if (findSubsequence(0, arr, subsequence, 0, targetSum)) {
        cout << "Subsequence with sum " << targetSum << " found: ";
        for (int num : subsequence) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No subsequence with sum " << targetSum << " found." << endl;
    }

    return 0;
}
