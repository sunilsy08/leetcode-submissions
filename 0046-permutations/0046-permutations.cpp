class Solution {
public:
    void helper(vector<int>& nums, int ind, int n , vector<vector<int>>&ans){
        if(ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<n; i++){
            swap(nums[ind], nums[i]);
            helper(nums, ind+1, n, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums, 0, nums.size(), ans);
        return ans;
    }
};