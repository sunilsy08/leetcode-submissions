class Solution {
public:
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
    string reverse(string s){
        int l =0;
        int r = s.size()-1;
        while(l<r){
            swap(s[l++], s[r--]);
        }
        return s;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = reverse(s);
        // reverse(s2.begin(), s2.end());
        return longestCommonSubsequence(s,s2);
    }   
};