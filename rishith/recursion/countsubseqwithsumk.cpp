#include <iostream>
#include <vector>
using namespace std;

// Recursive function to count subsequences with sum k
int countSubsequences(int index, vector<int>& arr, int currentSum, int targetSum) {
    // Base case: If the sum matches the target
    if (currentSum == targetSum) {
        return 1; // Found one valid subsequence
    }

    // Base case: If we've reached the end of the array
    if (index == arr.size()) {
        return 0;
    }

    // Include the current element in the subsequence
    int include = countSubsequences(index + 1, arr, currentSum + arr[index], targetSum);

    // Exclude the current element from the subsequence
    int exclude = countSubsequences(index + 1, arr, currentSum, targetSum);

    // Return the total count
    return include + exclude;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Input array
    int targetSum = 6;                // Target sum

    int count = countSubsequences(0, arr, 0, targetSum);
    cout << "Number of subsequences with sum " << targetSum << " is: " << count << endl;

    return 0;
}




// 1. What Does "Include" Mean?
// When we include the current element in the subsequence, we add it to the current sum and proceed to the next element. Any subsequences found in this case will have the current element as part of them.

// Example: If the array is {1, 2, 3} and the current element is 1, the "include" case will consider subsequences starting with 1 (like {1, 2}, {1, 3}, {1, 2, 3}).
// 2. What Does "Exclude" Mean?
// When we exclude the current element, we skip it entirely and proceed to the next element. Any subsequences found in this case will not have the current element.

// Example: If the array is {1, 2, 3} and the current element is 1, the "exclude" case will consider subsequences without 1 (like {2}, {3}, {2, 3}).
// 3. Adding the Counts Together
// The total number of valid subsequences with sum 
// 𝑘
// k is the sum of:

// All valid subsequences found by including the current element.
// All valid subsequences found by excluding the current element.
// This works because:

// The subsequences found in the "include" and "exclude" cases are completely independent of each other (they don’t overlap).
// Together, they cover all possible subsequences of the array.