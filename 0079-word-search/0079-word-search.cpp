class Solution {
public:
    int rowdel[4] = {-1, 0, 0, 1};
    int coldel[4] = {0, -1, 1, 0};
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int wordIndex, int n, int m){
        if(wordIndex == word.size()) return true;
        if(r<0 || r>=n || c<0 || c>=m) return false;

        if(board[r][c] != word[wordIndex]) return false;
        board[r][c] = '#';
        for(int i=0; i<4; i++){
            int nr = r + rowdel[i];
            int nc = c + coldel[i];
            if(dfs(board, word, nr, nc, wordIndex+1, n,m)){
                board[r][c] = word[wordIndex];
                return true;
            }
        }
        board[r][c] = word[wordIndex];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, word, i,j,0, n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};