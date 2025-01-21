bool subsetSum(vector<int>&nums, int k){
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        //initialization
        for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
        }

        //actual logic
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= k; j++){
                if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][k];
    }


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        sum += nums[i];

        if(sum % 2 != 0)
        return false;

        int k = sum/2;

        return subsetSum(nums,k);
    }

    