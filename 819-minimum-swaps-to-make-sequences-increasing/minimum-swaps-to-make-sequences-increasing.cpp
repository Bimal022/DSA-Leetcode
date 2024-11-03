#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, bool isSwapped, int index, vector<vector<int>>& dp) {
        if (index >= nums1.size()) {
            return 0;
        }
        
        // Use memoized result if available
        if (dp[index][isSwapped] != -1) {
            return dp[index][isSwapped];
        }

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        
        if (isSwapped) {
            swap(prev1, prev2);
        }
        
        // Option 1: Do not swap at the current index
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solve(nums1, nums2, false, index + 1, dp);
        }
        
        // Option 2: Swap at the current index
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, true, index + 1, dp));
        }
        
        // Memoize the result
        dp[index][isSwapped] = ans;
        return ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        
        // Initialize dp table with -1
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        // Start from the first index (1, as 0 is our padding)
        return solve(nums1, nums2, false, 1, dp);
    }
};
