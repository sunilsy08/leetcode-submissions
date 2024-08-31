class Solution {
public:
void perm(vector<int>nums, int ind,int n,set<vector<int>>&ans ){
    
    if(ind == n){
        ans.insert(nums); 
        return;
    }
    for(int i=ind; i<n; i++) {
        swap(nums[i], nums[ind]);
        perm(nums, ind+1, n, ans);
        swap(nums[i], nums[ind]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ansset;
        int n = nums.size();
         perm(nums,0,n,ansset);
         return vector<vector<int>>(ansset.begin(), ansset.end());
    }
};