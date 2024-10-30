class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int closestSum = INT_MAX / 2;  // Initialize with a very large number to avoid overflow

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int currentSum = nums[i] + nums[j] + nums[k];

                // Update closest sum if current sum is closer to target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
            }
        }
    }
    return closestSum;
}
};