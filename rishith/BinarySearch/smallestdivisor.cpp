You need to find the smallest positive integer divisor such that when each element of the array is divided by this divisor, 
the sum of the results is less than or equal to the given threshold (limit). If no such divisor exists, return -1.



Input:
arr = {1, 2, 3, 4, 5}
limit = 8
Explanation:
For each divisor d, calculate the sum:
Divide each element of arr by d.
Round each result up to the nearest integer (use the ceiling function).
Add all these values to get the sum.
Find the smallest divisor d such that the sum is ≤ limit.

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); // Size of the array
    int sum = 0;        // Initialize the sum
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div)); // Add the ceiling of arr[i]/div
    }
    return sum;         // Return the total sum
}
int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size(); // Size of the array
    if (n > limit) return -1; // Impossible case: More elements than the limit

    int low = 1;  // Smallest possible divisor
    int high = *max_element(arr.begin(), arr.end()); // Largest element in the array

    while (low <= high) {
        int mid = (low + high) / 2; // Midpoint of the range
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1; // Try smaller divisors
        } else {
            low = mid + 1; // Try larger divisors
        }
    }
    return low; // The smallest divisor that satisfies the condition
}
