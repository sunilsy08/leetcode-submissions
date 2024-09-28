class Solution {
public:
    int rowdel[4] = {-1,0,0,1};
    int coldel[4] = {0, -1, +1, 0};
    void dfs( vector<vector<char>>& grid, vector<vector<bool>>&visited,int r,int c,int n, int m){
        if(r<0 || r>=n || c<0 || c>=m || visited[r][c] || grid[r][c] == '0'){
            return;
        }
        visited[r][c] = true;
        for(int i=0; i<4; i++){
            int nr = r + rowdel[i];
            int nc = c + coldel[i];
            dfs(grid, visited, nr, nc, n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int n =grid.size();
        int m =grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] =='1'){
                    count++;
                    dfs(grid, visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};