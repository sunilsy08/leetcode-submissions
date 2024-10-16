class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<unsigned>>dp(m+1, vector<unsigned>(n+1, 0));

        dp[m-1][n-1] = 1;

        for(int i=m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;

                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};