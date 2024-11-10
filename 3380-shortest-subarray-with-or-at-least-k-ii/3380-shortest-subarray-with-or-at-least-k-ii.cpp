class Solution {
public:

    void addbits(vector<int>& bitCountAtPos, int k){
        for(int i=0; i<30; i++){
            if((1<<i) & k){
                bitCountAtPos[i] ++;
            }
        }
    }
    void subtractBits(vector<int>& bitCountAtPos, int k){
        for(int i=0; i<30; i++){
            if((1<<i) & k){
                bitCountAtPos[i]--;
            }
        }
    }
    bool isGreater(vector<int>& bitCountAtPos, int k){
        for(int i=29; i>=0; i--){
            if(((1<<i) & k)){
                if(bitCountAtPos[i] == 0)
                return false;
            } else if(bitCountAtPos[i] > 0){
                return true;
            }
        }
        return true;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int sum = 0;
        int minlen = INT_MAX;

        int left = 0;
        int right = 0;
        int n = nums.size();
        vector<int>bitCountAtPos(30,0);
        while(right < n){
            // sum += nums[right];

            // while(left <= right && sum >= k){
            //     minlen = min(minlen, right-left+1);
            //     sum -= nums[left];
            //     left++;
            // }
            // right++;
            addbits(bitCountAtPos, nums[right]);

            while(left <= right && isGreater(bitCountAtPos,k)){
                minlen = min(minlen, right-left+1);
                subtractBits(bitCountAtPos, nums[left]);
                left++;
            }
            right++;
        }
        return minlen == INT_MAX ? -1 : minlen;
    }
};