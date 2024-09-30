class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmin = 1;
        int currmax = 1;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                currmin = 1;
                currmax = 1;
                ans = max(ans,0);
                continue;
            }
            int temp = currmax*nums[i];
            currmax = max(nums[i], max(currmin*nums[i], currmax*nums[i]));
            currmin = min(nums[i], min(temp, currmin*nums[i]));
            ans = max(ans, currmax);
        }
        return ans;
    }
};