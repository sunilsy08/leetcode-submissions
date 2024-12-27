class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>rightMax(n, INT_MIN);

        for(int i= n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], values[i+1]) - 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, values[i] + rightMax[i]);
        }
        return ans;
    }
};