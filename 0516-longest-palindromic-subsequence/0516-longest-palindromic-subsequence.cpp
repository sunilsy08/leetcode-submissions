class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        // return helper(text1, text2, 0,0, text1.size(), text2.size());
        int n1 = text1.size(), n2= text2.size();
        int dp[n1+1][n2+1];
        memset(dp,0, sizeof(dp));
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--) {
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,x);
    }
};