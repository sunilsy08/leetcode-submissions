class Solution {
public:
    int rowdel[4] = {-1, 0 , 0 , 1};
    int coldel[4] = {0, -1, 1, 0};
    void dfs(vector<vector<char>>& grid, int r, int c, int n, int m, vector<vector<bool>>&visited){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == '0' || visited[r][c]){
            return;
        }
        visited[r][c] = true;

        for(int i=0; i<4; i++){
            int nr = r + rowdel[i];
            int nc = c + coldel[i];
            dfs(grid, nr, nc, n, m, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<bool>>visited(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, i,j, n,m, visited);
                    count++;
                }
            }
        }
        return count;
    }
};