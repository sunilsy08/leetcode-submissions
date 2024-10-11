class Solution {
public:
    void helper(vector<int>& candidates, int ind, int target, int n, vector<int>curr,
    vector<vector<int>>&ans){
        if(ind == n){
            return;
        }
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        // for(int i=ind; i< n; i++){
            if(candidates[ind] <= target){
                curr.push_back(candidates[ind]);
                helper(candidates, ind, target - candidates[ind], n, curr, ans);
                curr.pop_back();
            }
            helper(candidates, ind+1, target, n, curr, ans);
        // }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(candidates, 0, target, candidates.size(), curr, ans);
        return ans;
    }
};