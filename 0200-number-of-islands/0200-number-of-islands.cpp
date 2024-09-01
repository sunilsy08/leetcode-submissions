class Solution {
public:

    void dfs(vector<vector<char>>& grid, int n, int m, int r, int c,
    vector<vector<bool>>& visited
    ) {
        if(r<0 || c<0 || r>=n || c >=m || visited[r][c] || grid[r][c] == '0') return;
        visited[r][c] = true;

        dfs(grid, n,m, r+1, c, visited);
        dfs(grid, n,m, r-1, c, visited);
        dfs(grid, n,m, r, c+1, visited);
        dfs(grid, n,m, r, c-1, visited);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int islands = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, n, m, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};