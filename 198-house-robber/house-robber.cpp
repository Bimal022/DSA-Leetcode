class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>&dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int include = solve(nums, i+2, dp) + nums[i];
        int exclude = solve(nums, i+1, dp);
        return dp[i] = max(include, exclude);
    }
    int solveMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];

        if (n == 1) {
            return dp[0];
        }

        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int include = dp[i - 2] + nums[i];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        // int index = 0;
        // vector<int>dp(nums.size(), -1);
        // return solve(nums, index, dp);
        return solveMemo(nums);
    }
};