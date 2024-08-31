class Solution {
public:
void perm(vector<int>nums, int ind,int n,vector<vector<int>>&ans ){
    
    if(ind == n){
        ans.push_back(nums); 
        return;
    }
    for(int i=ind; i<n; i++) {
        swap(nums[i], nums[ind]);
        perm(nums, ind+1, n, ans);
        swap(nums[i], nums[ind]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
         perm(nums,0,n,ans);
         return ans;
    }
};