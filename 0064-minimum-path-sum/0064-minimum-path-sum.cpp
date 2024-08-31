class Solution {
public:
    int helper(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if(r==m-1 && c==n-1){
            return grid[r][c];
        }
        if(r>=m || c>=n) return INT_MAX;

        int down = helper(grid, r+1, c, m, n);
        int right = helper(grid, r, c+1, m,n);
        return min(down, right) + grid[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return helper(grid, 0, 0, grid.size(), grid[0].size());
        int m = grid.size(), n= grid[0].size();
        int dp[m][n];
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                }else {
                    int left = j<n-1 ? dp[i][j+1] : INT_MAX;
                    int up = i < m-1 ? dp[i+1][j] : INT_MAX;
                    dp[i][j] = min(left, up) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};