class Solution {
   public int findUnsortedSubarray(int[] nums) {
         int len = nums.length, left = -1, right = -2, min = nums[len-1], max = nums[0];
        for (int i=1; i<len; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[len-1-i]);
            if (nums[i] < max) right = i;
            if (nums[len-1-i] > min) left = len-1-i; 
        }
        return right - left + 1;
    }
}