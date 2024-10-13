class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        

        // Calculate the index of the 3x3 box
        // int boxIndex = (i / 3) * 3 + (j / 3);
        vector<vector<bool>> rowFreq(10,vector<bool>(10, false));
        vector<vector<bool>> colFreq(10,vector<bool>(10, false));
        vector<vector<bool>> boxFreq(10,vector<bool>(10, false));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    if(rowFreq[i][num] || colFreq[j][num] || boxFreq[boxIndex][num]){
                        return false;
                    }
                    rowFreq[i][num] = true;
                    colFreq[j][num] = true;
                    boxFreq[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};