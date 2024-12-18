class Solution {
public:
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
                int idx = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[idx] = nums[i];
            }
         }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return LISBinarySearch(nums);
    }
};