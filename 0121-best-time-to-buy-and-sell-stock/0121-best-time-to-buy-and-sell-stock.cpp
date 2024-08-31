class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevmin = INT_MAX;
        int ans = INT_MIN;

        for(int i=0; i<prices.size(); i++) {
            ans = max(ans, prices[i] - prevmin);
            prevmin = min(prevmin, prices[i]);
        }
        return max(ans,0);
    }
};