class Solution {
public:

    void helper(vector<int>& candidates, int target, int currSum,  vector<vector<int>>&ans, int ind, vector<int>curr){
        if(target == currSum){
            ans.push_back(curr);
            return;
        }
        if(currSum > target || ind >= candidates.size()){
            return;
        }
        curr.push_back(candidates[ind]);
        helper(candidates, target, currSum + candidates[ind], ans, ind, curr);
        curr.pop_back();
        helper(candidates, target, currSum, ans, ind+1, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int currSum = 0;
        helper(candidates, target, currSum, ans,0,curr);
        return ans;
    }
};