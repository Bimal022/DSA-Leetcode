class Solution {
    private:
    vector<int> solve(vector<int>& first, vector<int>& second) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] > second[j]) {
            ans.push_back(second[j]);
            j++;
        } else {
            ans.push_back(first[i]);
            i++;
        }
    }
    while (i < first.size()) {
        ans.push_back(first[i]);
        i++;
    }
    while (j < second.size()) {
        ans.push_back(second[j]);
        j++;
    }
    return ans;
}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        if (nums1.size() == 0) {
            merged = nums2;
        } else if (nums2.size() == 0) {
            merged = nums1;
        } else if (nums1[0] < nums2[0]) {
            merged = solve(nums1, nums2);
        } else {
            merged = solve(nums2, nums1);
        }
        int n = (merged.size() - 1) / 2;
        int x = merged.size();
        double ans;
        if (x % 2 == 0) {
            ans = (merged[n] + merged[n + 1]) / 2.0;
        } else {
            ans = merged[n];
        }
        return ans;
    }
};