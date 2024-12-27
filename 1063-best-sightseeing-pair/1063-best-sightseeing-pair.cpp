class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int lastMax = values[n-1] - 1;
        int ans = 0;

        for(int i= n-2; i>=0; i--) {
            ans = max(ans, values[i] + lastMax);
            lastMax = max(lastMax - 1, values[i] - 1);
        }
        return ans;
    }
};