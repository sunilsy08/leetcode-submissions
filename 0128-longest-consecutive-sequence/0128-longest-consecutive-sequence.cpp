class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>elements;

        for(int element: nums){
            elements.insert(element);
        }
        int maxSequenceLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(elements.count(nums[i] - 1) ==0){
                int curr = nums[i];
                int currSequenceCount = 0;
                while(elements.count(curr) > 0){
                    currSequenceCount++;
                    curr++;
                }
                if(currSequenceCount > maxSequenceLen){
                    maxSequenceLen = currSequenceCount;
                }
            }
        }
        return maxSequenceLen;
    }
};