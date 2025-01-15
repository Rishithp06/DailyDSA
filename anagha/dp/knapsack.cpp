#include <iostream>
#include <vector>
using namespace std;

int n, W;
//recursive
int knapsack(int[] wt, int[] val, int W, int n) {
        
        //base condition (smallest possible valid input)
        if(n == 0 || W == 0)
        return 0;

        //logic -> choice diagram
        if(wt[n-1] <= W)
        return max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));

        else 
        return knapsack(wt,val,W,n-1);
}



//memoization

int dp[n+1][W+1];
memset(dp,-1, sizeof(dp));

int knapsackMemoization(int[] wt, int[] val, int W, int n){
    //base condition
    if(n == 0 || W == 0)
    return 0;

    if(dp[n][W] != -1)
    return dp[n][W];

    //logic -> choice diagram
    if(wt[n-1] <= W)
    return dp[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));

    else
    return dp[n][W] = knapsack(wt,val,W,n-1);

}



//tabulation no recursion at all
int t[n+1][W+1];
int knapsackMemoization(int[] wt, int[] val, int W, int n){
    
    //initialize your matrix

    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< W+1; j++){
            if(i ==0 || j == 0)
            t[i][j] = 0;
        }
    }

    //actual logic

    for(int i = 1; i< n+1; i++){
        for(int j = 1; j< W+1; j++){
            if(wt[i-1] <= j)
            t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
            else
            t[i][j] = t[i-1][j];
        }
    }

    return t[n][W];
}


int main() {
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], val[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Recursive solution
    cout << "Maximum value (Recursive): " << knapsack(wt, val, W, n) << endl;

    // Memoization solution
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << "Maximum value (Memoization): " << knapsackMemoization(wt, val, W, n, dp) << endl;

    // Tabulation solution
    cout << "Maximum value (Tabulation): " << knapsackTabulation(wt, val, W, n) << endl;

    return 0;
}
