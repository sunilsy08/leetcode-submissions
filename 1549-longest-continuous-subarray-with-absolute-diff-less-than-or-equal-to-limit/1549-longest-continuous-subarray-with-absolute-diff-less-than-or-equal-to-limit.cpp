class Solution {
public:

    bool isValidWindow(deque<int>&mind, deque<int>&maxd, vector<int>&nums, int& limit){
        if(mind.empty() || maxd.empty()) return true;

        return (nums[maxd.front()] - nums[mind.front()]) <= limit;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>mind,maxd;

        int l=0,r=0;
        int ans = 0;

        while(r<nums.size()){
            while(!mind.empty() && nums[mind.back()] > nums[r]){
                mind.pop_back();
            }
            mind.push_back(r);

            while(!maxd.empty() && nums[maxd.back()] < nums[r]){
                maxd.pop_back();
            }
            maxd.push_back(r);

            while(!isValidWindow(mind,maxd,nums, limit)){
                if(l == mind.front()) mind.pop_front();
                if(l == maxd.front()) maxd.pop_front();
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};