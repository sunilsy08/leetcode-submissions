class Solution {
public:
    int rowdel[4] = {-1, 0 , 0 , 1};
    int coldel[4] = {0, -1, 1, 0};

    void dfs(int r, int c, int n, int m, vector<vector<char>>& board,vector<vector<bool>>&visited ) {
        if(r<0 || c<0 || r>=n || c>=m || visited[r][c] || board[r][c] != 'O') return;
        visited[r][c] = true;
        board[r][c] = 'Y';

        for(int i=0; i<4; i++) {
            int nr =r+rowdel[i];
            int nc = c+coldel[i];
            // if(!visited[nr][nc])
            dfs(nr,nc , n, m, board, visited);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        // Observation: All those zero's who are at boundary, or the zeros who are in touch with these boundary zeros can't be surrounded. Rest all can be converted.

        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O'){
                    dfs(i,j,n,m,board,visited);
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};