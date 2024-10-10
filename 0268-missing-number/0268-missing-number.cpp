class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = nums[0];
        int xor2 = 0^n;
        for(int i=1; i<n; i++){
            xor1= xor1^nums[i];
            xor2 = xor2^i;
        }
        return xor1^xor2;
    }
};