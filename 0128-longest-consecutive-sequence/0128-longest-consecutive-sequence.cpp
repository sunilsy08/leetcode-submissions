class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>elements;

        for(int element: nums){
            elements.insert(element);
        }
        int maxSequenceLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(elements.find(nums[i] - 1) == elements.end()){
                int curr = nums[i];
                int currSequenceCount = 0;
                while(elements.find(curr) != elements.end()){
                    currSequenceCount++;
                    curr++;
                }
                maxSequenceLen = max(maxSequenceLen, currSequenceCount);
            }
        }
        return maxSequenceLen;
    }
};