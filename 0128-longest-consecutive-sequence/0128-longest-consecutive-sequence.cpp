class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        
        int n = nums.size();
        if(n == 0)
            return 0;
        
        sort(nums.begin(), nums.end());

        int c = 1,lc = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1)
                    c++;
                else{
                    lc = max(lc, c);
                    c = 1;
                }
            }
        }
        return max(lc, c);
    }
};