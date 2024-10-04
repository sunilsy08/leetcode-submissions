class Solution {
public:

    void helper(vector<int>& candidates, int target, int currSum,  vector<vector<int>>&ans, int ind, vector<int>curr){
        if(target == currSum){
            ans.push_back(curr);
            return;
        }
        // if(ind >= candidates.size()){
        //     return;
        // }
        if(currSum + candidates[ind] <= target){
            curr.push_back(candidates[ind]);
            helper(candidates, target, currSum + candidates[ind], ans, ind, curr);
            curr.pop_back();
        }
        if(ind+1< candidates.size()){
            helper(candidates, target, currSum, ans, ind+1, curr);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        ios_base::sync_with_stdio(false);

        // vector<vector<int>>memo(target+1, vector<int>(candidates.size()+1));
        vector<int>curr;
        int currSum = 0;
        helper(candidates, target, currSum, ans,0,curr);
        return ans;
    }
};