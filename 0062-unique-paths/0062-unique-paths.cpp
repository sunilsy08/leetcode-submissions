class Solution {
public:
    // bool isvalid(int r, int c,int m, int n) {
    //     if (r<0 || r >=m || c<0 || c>= n) return false;
    //     return true;
    // }
    // int helper(int r, int c, int m, int n) {
    //     if(r == m-1 && c== n-1) return 1;
    //     if(!isvalid(r,c,m,n)) return 0;
    //     int rightways = helper(r, c+1, m, n);
    //     int downways = helper(r+1, c, m, n);
    //     return rightways+ downways;

    // }
    
    // int uniquePaths(int m, int n) {
    //     return helper(0,0,m,n);
    // }

    int uniquePaths(int m, int n) {
        long long dp[m+1][n+1];
        dp[m][n] = 1;
        for(int r=m;r>=0;r--) {
            for(int c=n;c>=0;c--) {
                if(r == m && c ==n) dp[r][c] = 1;
                else if(r==m) dp[r][c] = dp[r][c+1];
                else if(c==n) dp[r][c] = dp[r+1][c];
                else {
                    long long  rways= dp[r][c+1];
                    long long dways = dp[r+1][c];
                    dp[r][c] = rways + dways;
                }
            }
        }
        return dp[1][1];
    }
};