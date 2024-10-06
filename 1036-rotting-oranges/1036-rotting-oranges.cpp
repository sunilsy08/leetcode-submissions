class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        int totalfresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                } else if (grid[i][j] == 1){
                    totalfresh++;
                }
            }
        }
        if(totalfresh == 0) return 0;
        int rowdel[4] = {-1,0,0,1};
        int coldel[4] = {0,-1,1,0};
        int time =0;
        while(!q.empty()){
            int currtime = q.front().second;
            int r = q.front().first.first;
            int c = q.front().first.second;
            q.pop();
            time = max(time,currtime);
            // totalfresh--;
            // if(totalfresh ==0){
            //     return currtime;
            // }

            for(int i=0; i<4; i++){
                int nr = r+rowdel[i];
                int nc = c + coldel[i];
                if(nr>=0 && nc>=0 && nr<m && nc <n && grid[nr][nc] == 1){
                    q.push({{nr,nc}, currtime+1});
                    totalfresh--;
                    grid[nr][nc] = 2;
                    if(totalfresh ==0){
                        return currtime+1;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};