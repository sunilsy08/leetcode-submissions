class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum,0);
        }
        return ans;
    }
};