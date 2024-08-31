class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high) {
            mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;

        // Check if we are in left sorted part
            if(nums[low] <= nums[mid]) {
                // Condition to move to right side:
                if(target<nums[low] || target> nums[mid]){
                    low =mid+1;
                } else {
                    high = mid-1;
                }
            }
            else {
                // Condition to move to left part:
                if(target > nums[high] || nums[mid] > target) {
                    high = mid-1;
                } else {
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};