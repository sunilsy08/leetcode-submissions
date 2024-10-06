class Solution {
public:
   bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(target == nums[mid]) return true;
// Check if we are in left half of sorted array
            if(nums[mid] == nums[l] && nums[mid] == nums[r]){
                l++;
                r--;
            } else if(nums[l] <= nums[mid]){
                    if(nums[l]<=target && target < nums[mid]){
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
            } else {
                if(target > nums[mid] && target <= nums[r]){
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return false;
    }
};