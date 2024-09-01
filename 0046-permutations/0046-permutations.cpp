class Solution {
public:
    void helper(vector<int>& nums,int ind,vector<vector<int>>& ans, int n) {
        if(ind == n) {
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<n; i++) {
            swap(nums[i], nums[ind]);
            helper(nums, ind+1, ans, n);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        helper(nums, 0, ans, n);
        return ans;
    }
};