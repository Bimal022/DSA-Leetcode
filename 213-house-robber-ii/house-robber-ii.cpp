class Solution {
public:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) {
            return 0;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        int include = solve(nums, start + 2, end, dp) + nums[start];
        int exclude = solve(nums, start + 1, end, dp);
        return dp[start] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // Case 1: Include the first house, exclude the last house
        vector<int> dp1(n, -1);
        int first_include = solve(nums, 0, n - 2, dp1);

        // Case 2: Exclude the first house, include the last house
        vector<int> dp2(n, -1);
        int first_exclude = solve(nums, 1, n - 1, dp2);

        return max(first_include, first_exclude);
    }
};
