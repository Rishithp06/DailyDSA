#include <iostream>
using namespace std;

// Recursive function to generate all binary strings
void generateBinaryStrings(int n, string prefix = "") {
    // Base case: when the desired length is reached
    if (n == 0) {
        cout << prefix << endl; // Print the complete binary string
        return; // Terminate the current recursion branch
    }

    // Recursive case 1: Add '0' to the current prefix and recurse for the next position
    generateBinaryStrings(n - 1, prefix + "0");

    // Recursive case 2: Add '1' to the current prefix and recurse for the next position
    generateBinaryStrings(n - 1, prefix + "1");
}

int main() {
    int length;
    cout << "Enter the length of binary strings: ";
    cin >> length;

    // Call the recursive function with the input length
    generateBinaryStrings(length);

    return 0;
}
