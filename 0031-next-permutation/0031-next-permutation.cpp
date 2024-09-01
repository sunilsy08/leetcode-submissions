class Solution {
public:
    int getbreakingPoint(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]){
                return i;
            }
        }
        return -1;
    }
    void reverse(vector<int>&nums, int l, int r) {
        while(l<r){
            swap(nums[l++], nums[r--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int bp = getbreakingPoint(nums);
        int n = nums.size();
        if(bp == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>bp; i--) {
            if(nums[bp] < nums[i]){
                swap(nums[bp], nums[i]);
                break;
            }
        }
        reverse(nums, bp+1, n-1);
    }
};