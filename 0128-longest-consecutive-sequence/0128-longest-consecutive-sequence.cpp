class Solution {
public:
    

    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        // for(auto it: s) {
        //     cout<<it<<" ";
        // }
        int count = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(s.find(nums[i]-1) == s.end()) {
                 count = 1;
                int num = nums[i];
                while(s.find(num + 1) != s.end()) {
                    count++;
                    num = num +1;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};