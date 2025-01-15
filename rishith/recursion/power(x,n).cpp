class Solution {
public:
    double myPow(double x, int n) {
        // Base case: any number to the power 0 is 1
        if (n == 0) return 1;

        // Handle negative n by using long long to avoid overflow
        long long N = n; // Convert n to long long
        if (N < 0) {
            N = -N; // Take absolute value of N
            x = 1 / x; // Invert x for negative power
        }

        // Recursive case: split the power
        double half = myPow(x, N / 2);

        // If N is even
        if (N % 2 == 0) return half * half;

        // If N is odd
        return half * half * x;
    }
};
