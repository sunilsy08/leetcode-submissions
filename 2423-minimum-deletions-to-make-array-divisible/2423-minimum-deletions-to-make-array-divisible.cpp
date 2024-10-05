class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0) return a;

        return gcd(b, a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int computedgcd = 0;
        for(int i=0; i<numsDivide.size(); i++){
            computedgcd = gcd(computedgcd, numsDivide[i]);
        }

        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(computedgcd%nums[i] == 0){
                return count;
            } 
            count++;
        }
        return -1;
    }
};