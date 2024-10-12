class Solution {
public:
    int hammingWeight(int n) {
        
        int count = 0;

        for(int i=0; i<32; i++){
            int lastbit = n&1;

            if(lastbit != 0) count++;
            n = n>>1;
        }
        return count;
    }
};