class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<k-1; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        int l =0, r =k-1;
        while(r<n){
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            ans.push_back(nums[dq.front()]);

            if(l == dq.front()) dq.pop_front();
            l++;
            r++;
        }
        return ans;
    }
};