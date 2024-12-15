class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int MOD = 1e9 + 7;
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int maxh = 0;
        int maxw = 0;
        int prev = 0;
        for(int i=0; i<horizontalCuts.size(); i++){
            maxh = max(maxh, horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        maxh = max(maxh, h - prev);
        prev = 0;
        for(int i=0; i<verticalCuts.size(); i++){
            maxw = max(maxw, verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        maxw = max(maxw, w - prev);
        return ((long)maxh * (long)maxw) % MOD;
    }
};