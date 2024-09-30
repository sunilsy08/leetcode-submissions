
class Solution {
public:


    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = INT_MIN;

        for (int sc = 0; sc < m; sc++) {
            vector<int> sum(n, 0);
            for (int ec = sc; ec < m; ec++) {
                for (int row = 0; row < n; row++) {
                    sum[row] += matrix[row][ec];
                }
                for (int i = 0; i < n; i++) {
                    int currentSum = 0;
                    for (int j = i; j < n; j++) {
                        currentSum += sum[j];
                        if (currentSum <= k) {
                            ans = max(ans, currentSum);
                        }
                    }
                }
            }
        }
        return ans;
    }
};