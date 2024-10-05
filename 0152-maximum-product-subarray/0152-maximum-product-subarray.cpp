class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = 1;
        int currMax = 1;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                currMin = 1;
                currMax = 1;
                ans = max(ans,0);
                continue;
            }
            int temp = currMax*nums[i];
            currMax = max(nums[i], max(currMin*nums[i], currMax*nums[i]));
            currMin = min(nums[i], min(currMin*nums[i], temp));
            ans = max(ans, currMax);
        }
        return ans;
    }
};