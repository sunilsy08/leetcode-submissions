class Solution {
public:
    long long helper(vector<vector<int>>& questions, int ind, vector<long long>&dp){
        if(ind >= questions.size()) return 0;
        if(dp[ind] != -1) return dp[ind];

        long long l = questions[ind][0] + helper(questions, ind+questions[ind][1]+1, dp);
        long long r = helper(questions, ind+1, dp);
        return dp[ind]= max(l,r);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); 
        
        for (int i = n - 1; i >= 0; i--) {
            long long skipCurrent = dp[i + 1];  
            int nextQuestion = i + questions[i][1] + 1;
            long long takeCurrent = questions[i][0];  
            if (nextQuestion < n) {
                takeCurrent += dp[nextQuestion];
            }
            
            dp[i] = max(takeCurrent, skipCurrent);
        }
        
        return dp[0]; 
        // return helper(questions, 0, dp);
    }
};