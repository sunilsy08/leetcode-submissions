class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;

        while(low<=high) {
            mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;

            //  We are in left sorted array
            if(nums[low] <= nums[mid]) {
                if(target<nums[low] || target > nums[mid]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            } else {
                if(nums[high] < target || nums[mid] > target) {
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
        }
        return -1;
    }
};