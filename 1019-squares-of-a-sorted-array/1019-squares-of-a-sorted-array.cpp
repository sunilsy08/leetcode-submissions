class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l =0;
        int n = nums.size();
        int r = n-1;
        int ind = n-1;
        vector<int>ans(n);
        while(l<=r) {
            int left = nums[l]*nums[l];
            int right = nums[r]*nums[r];
            if(left>right){
                ans[ind--] = left;
                l++;
            } else {
                ans[ind--] = right;
                r--;
            }
        }
        return ans;
    }
};