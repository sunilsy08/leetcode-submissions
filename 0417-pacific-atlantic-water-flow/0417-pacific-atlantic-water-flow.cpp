class Solution {
public:
    int rowdel[4] = {-1, 0 , 0, 1};
    int coldel[4] = {0, -1, 1, 0};
    void bfs(vector<vector<int>>& heights,vector<vector<bool>>&visited , queue<pair<int,int>>&q, int n, int m ){

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
             for (int i = 0; i < 4; i++) {
                int nr = r + rowdel[i];
                int nc = c + coldel[i];
                
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc]
                    && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>atlanticVisited(n, vector<bool>(m, false));
        vector<vector<bool>>pacificVisited(n, vector<bool>(m, false));
        queue<pair<int,int>>pacificQueue;
        queue<pair<int,int>>atlanticQueue;

        for(int i=0; i<n; i++){
            pacificVisited[i][0] = true;
            pacificQueue.push({i,0});
            atlanticVisited[i][m-1] = true;
            atlanticQueue.push({i,m-1});
        }
        for (int i = 0; i < m; i++) {
            pacificVisited[0][i] = true;
            pacificQueue.push({0, i});
            atlanticVisited[n - 1][i] = true;
            atlanticQueue.push({n - 1, i});
        }
        // for(int i=0; i<m; i++){
        //     pacificVisited[0][i] = true;
        //     atlanticVisited[i][n-1] = true;
        //     pacificQueue.push({0,i});
        //     atlanticQueue.push({n-1,i});
        // }

        bfs(heights,atlanticVisited, atlanticQueue,n, m);
        bfs(heights,pacificVisited, pacificQueue, n, m);
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlanticVisited[i][j] && pacificVisited[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};