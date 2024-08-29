class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1;
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]){
                l = i;
                break;
            }
        }
        if(l == -1) return 0;
        int r =-1;
        for(int j = n-1; j>0; j--) {
            if(nums[j] < nums[j-1]){
                r = j;
                break;
            }
        }
        
        int minval = INT_MAX;
        int maxval = INT_MIN;

        for(int i = l; i<=r; i++) {
            minval = min(minval, nums[i]);
            maxval = max(maxval, nums[i]);
        }

        while(l>0 && nums[l-1] > minval){
            l--;
        }
        while(r<n-1 && nums[r+1] < maxval){
            r++;
        }
        return r-l+1;
    }
};