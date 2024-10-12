class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void mirror(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            int l = 0, r = matrix.size()-1;
            while(l<r){
                swap(matrix[i][l++], matrix[i][r--]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
    }
};