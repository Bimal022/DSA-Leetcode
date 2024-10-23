class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }else{
            return a[0] < b[0];
        }
    }
    int LISBinarySearch(vector<int>&nums){
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=0; i<n; i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i])-                               temp.begin();
                temp[idx] = nums[i];
            }
         }
        return len;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int>nums;
        for(int i=0; i<envelopes.size(); i++){
            nums.push_back(envelopes[i][1]);
        }
        return LISBinarySearch(nums);
    }
};