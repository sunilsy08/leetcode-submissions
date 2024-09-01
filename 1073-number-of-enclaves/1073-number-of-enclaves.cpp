class Solution {
public:
    bool isvalid(int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(r<0 || c<0 || r>=n || c>=m || visited[r][c] || grid[r][c] != 1) return false;
        return true;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((grid[i][j] == 1) && (i==0 || j== 0 || i== n-1 || j== m-1)) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        int rowdel[4] = {-1, 0, 0 , 1};
        int coldel[4] = {0, -1, 1, 0};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r + rowdel[i];
                int nc = c + coldel[i];

                if(isvalid(nr,nc,n,m,grid,visited)){
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        int count =0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == 1)
                count++;
            }
        }
        return count;
    }
};