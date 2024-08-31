class Solution {
public:
void perm(vector<int>nums, int ind,int n,vector<vector<int>>&ans, vector<int>temp ){
    
    if(ind == n){
        ans.push_back(temp); 
        return;
    }
    for(int i=ind; i<n; i++) {
        swap(nums[i], nums[ind]);
        temp.push_back(nums[ind]);
        perm(nums, ind+1, n, ans, temp);
        temp.pop_back();
        swap(nums[i], nums[ind]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int>temp;
         perm(nums,0,n,ans, temp);
         return ans;
    }
};