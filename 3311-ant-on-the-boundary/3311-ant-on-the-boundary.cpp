class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int currPos = 0;
        int count = 0;
        for(int num : nums){
            currPos += num;
            if(currPos == 0) count++;
        }
        return count;
    }
};