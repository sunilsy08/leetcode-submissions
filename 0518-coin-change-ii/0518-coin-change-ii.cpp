class Solution {
public:
    void helper(int amount, vector<int>&coins, int n, int &ans){
        if(amount == 0){
            ans++;
            return;
        }
        if(amount <0 || n<0) return;
        int remAmount = amount - coins[n];
        
        helper(remAmount, coins, n, ans);
        helper(amount, coins, n-1, ans);
    }
    int change(int amount, vector<int>& coins) {
        int ans = 0;
        int n = coins.size();
        vector<unsigned>dp(amount+1, 0);
        dp[0] = 1;

        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<=amount; j++){
                dp[j] = dp[j] + (j-coins[i] >=0 ? dp[j-coins[i]] :0);
            }
        }
        return dp[amount];
    }
};