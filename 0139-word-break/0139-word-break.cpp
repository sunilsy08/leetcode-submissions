class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1);
        dp[n] = true;
        
        for(int i=n-1; i>=0; i--){
            for(string word : wordDict){
                int wordlen = word.size();

                if(i + wordlen <= n && s.substr(i, wordlen) == word){
                    dp[i] = dp[i + wordlen];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};