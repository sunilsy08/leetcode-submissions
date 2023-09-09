class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int row0= 1;
        int m = matrix.size();
        int n = matrix[0].size();

/* To avoid using extra space we will use first row and first column
    to store whether the entire row or entire column needs to be updated.
*/

// Storing Whether first column needs to be all 0 or not

        for(int i=0; i <m ; i++) {
            if(matrix[i][0] == 0)
                col0 = 0;
        }

// Storing Whether first row needs to be all 0 or not

        for(int i=0; i <n ; i++) {
            if(matrix[0][i] == 0)
                row0 = 0;
        }


        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] ==0 ) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(col0 == 0) {
            for(int i=0; i<m; i++) 
            matrix[i][0] = 0;
        }

        if(row0 == 0) {
            for(int i=0; i<n; i++) 
            matrix[0][i] = 0;
        }

    }
};