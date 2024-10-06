class Solution {
public:
    bool KSubsetsWithTargetSumPossible(vector<int>& nums, int i,int currSum,  int k,vector<bool>&used, int target ){
        if(k == 0) return true;
        if(currSum == target) {
            return KSubsetsWithTargetSumPossible(nums, 0, 0, k-1, used, target);
        }

        for(int st = i; st<nums.size(); st++){
            if(!used[st] && currSum + nums[st] <= target){
                used[st] = true;
                if(KSubsetsWithTargetSumPossible(nums, st+1, currSum + nums[st], k, used, target)){
                    return true;
                }
                used[st] = false;
            }
        }   
        return false;
 }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int sum =  accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;

        int target = sum/k;
        if(*max_element(nums.begin(), nums.end()) > target) return false;
        vector<bool>used(n,false);   

        return KSubsetsWithTargetSumPossible(nums, 0,0,k, used, target);
    }
};