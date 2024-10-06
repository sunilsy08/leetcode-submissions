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
        vector<long long>dp(n, -1);
        // if(n<=3){
        //     int ans = INT_MIN;
        //     for(int i=0; i<n; i++){
        //         ans = max(ans, questions[i][0]);
        //     }
        // }

        // vector<long long>dp(n,0);
        // // dp[0] = questions[0][0];
        // // dp[1] = questions[1][0];
        // // dp[2] = questions[2][0];
        // for(int i=n-1; i>=0; i--){
        //     int nextQuestion = i + questions[i][1];
        //     long long nextQuestionPoints = 0;
        //     if(nextQuestion < n) nextQuestionPoints = dp[nextQuestionPoints];
        //     long long r = i!= n-1 ? dp[i+1] : 0;
        //     long long l = questions[i][0] + nextQuestionPoints;
        //     dp[i] = max(l,r);
        // }
        // long long ans = INT_MIN;
        // for(int i=0; i<n; i++){
        //     ans = max(ans, dp[i]);
        // }
        // return ans;
        return helper(questions, 0, dp);
    }
};