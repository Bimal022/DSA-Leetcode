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
    int rob(vector<int>& nums) {
        int index = 0;
        vector<int>dp(nums.size(), -1);
        return solve(nums, index, dp);
    }
};