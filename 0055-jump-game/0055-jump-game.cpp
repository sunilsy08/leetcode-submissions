class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        vector<bool>dp(n, false);

        dp[n-1] = true;

        for(int i=n-2; i>=0; i--){
            int curr = i;

            for(int jump = 1; jump <= nums[i]; jump++){
                int nextIndex = curr + jump;
                if(nextIndex < n){
                    dp[i] = dp[i] || dp[nextIndex];
                }
                if(dp[i]) break;
            }
            // cout<<"dp["<<i<<"]"<< (dp[i] ? "true\n":"false\n");
            // break;
        }
        return dp[0];

    }
};