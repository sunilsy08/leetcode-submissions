class Solution {
public:
 bool kSubsetsWithTargetPossible(vector<int>& nums, int i,int currSum,  int k,vector<bool>&used, int target ){
        if(k==0){
            return true;
        }
        if(currSum == target){
            return kSubsetsWithTargetPossible(nums, 0, 0, k-1, used, target);
        }

        for(int st = i; st<nums.size(); st++){
            if(!used[st] && currSum + nums[st] <= target){
                used[st] = true;
                if(kSubsetsWithTargetPossible(nums, st+1, currSum+nums[st], k, used, target)){
                    return true;
                }
                used[st] = false;

            }
        }
        return false;
 }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int num: nums){
            sum += num;
        }
        if(sum%k != 0) return false;
        int target = sum/k;
// IMP
        if(*max_element(nums.begin(), nums.end()) > target) return false;
        vector<bool>taken (n, false);
        return kSubsetsWithTargetPossible(nums, 0, 0, k, taken, target);
    }
};