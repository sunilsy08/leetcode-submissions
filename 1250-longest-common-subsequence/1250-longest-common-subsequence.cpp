class Solution {
public:
    int helper(string &s1, string &s2, int i, int j, int n1, int n2){
        if(i == n1 || j == n2) return 0;
        
        if(s1[i] == s2[j]){
            return 1 + helper(s1, s2, i+1, j+1, n1,n2);
        }
        return max(
            helper(s1,s2,i+1,j,n1,n2),
            helper(s1,s2,i,j+1,n1,n2)
        );

    }
    int longestCommonSubsequence(string text1, string text2) {
        // return helper(text1, text2, 0,0, text1.size(), text2.size());
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};