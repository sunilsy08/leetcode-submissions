class Solution {
public:
    int climbStairs(int n) {
        if(n <=2) return n;

        int lastStep = 2;
        int lastTwoStep = 1;
        
        for(int i=3; i<=n; i++){
            int currStepWays = lastStep + lastTwoStep;
            lastTwoStep = lastStep;
            lastStep = currStepWays;
        }
        return lastStep;
    }
};