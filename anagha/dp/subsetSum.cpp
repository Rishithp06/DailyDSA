#include <iostream>
#include <vector>
using namespace std;

int n, sum;


//tabulation no recursion at all
int t[n+1][sum+1];
int subsetSum(int[] wt, int sum){
    
    //initialize your matrix

    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< sum+1; j++){
            if(i ==0)
            t[i][j] = 0;
            if(j == 0)
            t[i][j] = 1;
        }
    }

    //actual logic

    for(int i = 1; i< n+1; i++){
        for(int j = 1; j< sum+1; j++){
            if(wt[i-1] <= j)
            t[i][j] = t[i-1][j-wt[i-1]] || t[i-1][j];
            else
            t[i][j] = t[i-1][j];
        }
    }

    return t[n][sum];
}


int main() {
    cout << "Enter the number of items: ";
    cin >> n;


    return 0;
}
