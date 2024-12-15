class Solution {
public:
// O(N^2)
/*
    int helper(){
        int n = nums.size();
        vector<int>lis(n, 1);
        lis[0] = 1;
        for(int i=1; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[j] < nums[i] && lis[i] < 1 + lis[j]) {
                    lis[i] = 1 + lis[j];
                }
            }
        }
        return *max_element(begin(lis), end(lis));

    }
*/
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        sub.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(*sub.rbegin() < nums[i]) {
                sub.push_back(nums[i]);
            } else {
                int index = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                sub[index] = nums[i];
            }
        }
        return sub.size();
    }
};