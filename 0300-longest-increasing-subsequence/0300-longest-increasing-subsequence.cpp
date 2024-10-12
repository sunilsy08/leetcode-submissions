class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *(max_element(dp.begin(), dp.end()));
    }
};