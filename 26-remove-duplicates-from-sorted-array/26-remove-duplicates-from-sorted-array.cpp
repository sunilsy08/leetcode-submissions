class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int last = 1;
        int curr = 0;
        
        while(curr < nums.size()) {
            if(nums[last-1] != nums[curr]) {
                nums[last] = nums[curr];
                last++;
            }
            
            curr++;
        }
        return last;
    }
};