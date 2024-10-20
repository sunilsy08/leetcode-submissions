class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonalSquare = 0;
        map<int,double>roots;
        int ans = 0;

        for(auto rectangle : dimensions){
            long long prod1 = (long long)rectangle[0]*(long long)rectangle[0];
            long long prod2 = (long long)rectangle[1]*(long long)rectangle[1];
            long long diagonalSquare = prod1 + prod2;
            
            if(diagonalSquare > maxDiagonalSquare){
                maxDiagonalSquare = diagonalSquare;
                ans = rectangle[0]*rectangle[1];
            } else if (diagonalSquare == maxDiagonalSquare) {
                ans = max(ans, rectangle[0]*rectangle[1]);
            }
        }
        return ans;
    }
};