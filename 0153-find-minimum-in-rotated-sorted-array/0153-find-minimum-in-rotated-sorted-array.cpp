class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        int low = 0, high = size-1;
        // Means array not rotated or single element
        if(nums[low] <= nums[high]){
            return nums[low];
        }

        while(low<=high){
            int mid = low + (high - low)/2;

            if(mid > 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }

            if(mid < size-1 && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }

            if(nums[mid] > nums[low]){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return -1;
    }
};