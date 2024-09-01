class Solution {
public:
    int rowdiff[4] = {-1, 0, 0 , 1};
    int coldiff[4] = {0, -1, 1, 0};
    
    bool isvalid(int r, int c, vector<vector<int>>grid, int n, int m){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] !=1) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>>q;

        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }
        int minutes = 0;
        while(!q.empty()) {
            // pair<int,int>p = 
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            minutes = max(minutes, time);

            for(int i=0; i<4; i++) {
                    int nr = r+rowdiff[i];
                    int nc = c+ coldiff[i];
                    if(isvalid(nr, nc, grid, n, m)){
                        grid[nr][nc] = 2;
                        q.push({{nr, nc}, time+1});
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes;
    }
};