class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n <=1) return true;

        int maxReachable = nums[0];

        for(int i=1; i<=maxReachable; i++){
            int canReach = nums[i] + i;
            maxReachable = max(maxReachable, canReach);
            if(i == n-1) return true;
        }
        return false;
    }
};