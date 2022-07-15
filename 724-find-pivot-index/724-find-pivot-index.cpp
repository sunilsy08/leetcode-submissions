class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long int sum = 0;
        for(int i=0;i<nums.size(); i++) {
            sum += nums[i];
        }
        
        int ans = -1;
        long lsum = 0;
        if(sum == nums[0]) return 0;
        for(int i=1; i< nums.size(); i++) {
            lsum +=  nums[i-1];
            if (lsum == (sum - lsum - nums[i]))
                return i;
        }
        return -1;
    }
};