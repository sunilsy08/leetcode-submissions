class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int house =2; house<n; house++){
            dp[house] = max(
                nums[house] + dp[house-2],
                dp[house-1]
            );
        }
        return dp[n-1];
    }
};