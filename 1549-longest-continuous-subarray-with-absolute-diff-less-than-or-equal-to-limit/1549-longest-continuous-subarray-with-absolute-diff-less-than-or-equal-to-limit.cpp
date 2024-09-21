class Solution {
public:
    bool isValidWindow(deque<int>&minelements,deque<int> &maxelements, vector<int>& nums, int limit){
        if(minelements.size() == 0 || maxelements.size() == 0) return true;
        return (nums[maxelements.front()] - nums[minelements.front()]) <= limit;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>minelements, maxelements;
        int ans =0;
        int l=0, r=0;
        int n = nums.size();
        while(r<nums.size()){
            while(!minelements.empty() && nums[minelements.back()] > nums[r]){
                minelements.pop_back();
            }
            minelements.push_back(r);
            while(!maxelements.empty() && nums[maxelements.back()] < nums[r]){
                maxelements.pop_back();
            }
            maxelements.push_back(r);

            while(l<=r && !isValidWindow(minelements, maxelements, nums, limit)){
                if(l == minelements.front()){
                    minelements.pop_front();
                }
                if(l== maxelements.front()){
                    maxelements.pop_front();
                }
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};