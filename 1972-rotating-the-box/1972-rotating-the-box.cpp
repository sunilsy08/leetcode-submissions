class Solution {
public:
    vector<vector<char>> rotateMatrix(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
    
        // Create a result matrix of size n x m
        vector<vector<char>> res(n, vector<char>(m));
    
        // Move mat[i][j] to res[j][m - i- 1]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - i - 1] = mat[i][j];
            }
        }
        return res;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>>ans =  rotateMatrix(box);
        
        for(int i=0; i<ans[0].size(); i++) {
            int lastObstacle = ans.size();
            for(int j = ans.size() - 1; j >=0 ; j--) {
                if(ans[j][i] == '*') {
                    lastObstacle = j;
                } else if(ans[j][i] == '#'){
                    ans[j][i] = '.';
                    ans[lastObstacle-1][i] = '#';
                    lastObstacle--;
                }
            }
        }
        return ans;
    }
};