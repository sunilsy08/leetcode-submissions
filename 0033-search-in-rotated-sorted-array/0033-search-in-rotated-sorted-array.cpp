class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return -1;
        if(size == 1){
            return nums[0] == target ? 0 : -1;
        }
        int low = 0, high = size -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else {
                if(target > nums[mid] && target <= nums[high]){
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};