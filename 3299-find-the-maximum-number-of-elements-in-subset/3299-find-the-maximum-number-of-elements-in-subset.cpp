class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int,int>freq;
        int maxEl = nums.back();

        for(int num : nums){
            freq[num]++;
        }
        
        int count = 0;
        int ans = 1;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            count = 0;
            
            while(freq[x] > 0){
                if(freq[x] == 1){
                    freq[x]--;
                    count++;
                    if(count % 2 == 0){
                        count --;
                    }
                    break;
                } else {
                    freq[x] -=2;
                    count +=2;
                }
                if(x <= maxEl/x){
                    x = x*x;
                } else {
                    break;
                }
            }
            if(count % 2 == 0) count--;
            ans = max(ans, count);
        }
        return ans;
    }
};