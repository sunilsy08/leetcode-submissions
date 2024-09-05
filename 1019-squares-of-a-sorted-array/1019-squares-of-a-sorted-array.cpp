class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);

        int l =0, r = n-1;
        int ind = n-1;
        while(l<=r){
            int leftSquare = nums[l]*nums[l];
            int rightSquare = nums[r]*nums[r];
            if( leftSquare > rightSquare ){
                ans[ind--] = leftSquare;
                l++;
            } else {
                ans[ind--] = rightSquare;
                r--;
            }
        }
        return ans;
    }
};