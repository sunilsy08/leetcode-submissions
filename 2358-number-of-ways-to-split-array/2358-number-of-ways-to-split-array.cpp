class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long totalsum = 0;
        for(int i=0; i<n; i++) {
            totalsum += nums[i];
        }
        int count =0;
        long leftsum =0;
        for(int i=0; i<n-1; i++) {
            leftsum += nums[i];
            long rightsum = totalsum - leftsum;
            if(leftsum >= rightsum){
                count++;
            }
        }
        return count;
    }
};