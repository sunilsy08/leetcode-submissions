class Solution {
public:
    void helper(vector<int>& nums, int ind, int & count, int maxOr, int currOr){
        if(ind == nums.size()){
            if(currOr == maxOr){
                count++;
            }
            return;
        }
        helper(nums, ind+1, count, maxOr, currOr);
        helper(nums, ind+1, count, maxOr, currOr | nums[ind]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for(int num : nums){
            maxOr = maxOr | num;
        }
        int count = 0;
        helper(nums, 0, count, maxOr,0);
        return count;
    }
};