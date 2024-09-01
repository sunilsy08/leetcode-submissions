class Solution {
public:
    bool isvalid(int r, int c, int n, int m, vector<vector<int>>& mat,
    vector<vector<int>>& ans
    ) {
        if(r<0 || c<0 || r>=n || c>=m || mat[r][c] == 0 || ans[r][c] != INT_MAX) {
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    // Every 0 is at 0 dist from 0
                    q.push({{i,j}, 0});
                }
            }
        }

        int rowdel[4] = {-1, 0 , 0 , 1};
        int coldel[4] = {0, -1, 1, 0};
        vector<vector<int>>ans(n, vector<int>(m,INT_MAX));
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[r][c] = min(ans[r][c], dist);

            for(int i=0; i<4; i++) {
                int nr = r+rowdel[i];
                int nc = c+coldel[i];
                if(isvalid(nr,nc,n,m,mat, ans)){
                    q.push({{nr,nc}, dist+1});
                }
            }
        }
        return ans;
    }
};