class Solution {
public:
    int hammingWeight(int n) {
        
        int count = 0;
        // IF INTERVIEWER MODIFIES THAT THERE CAN BE NEGATIVE NUMBERS
        unsigned int num = static_cast<unsigned int>(n);
        // NOTE THAT SIMPLY MAKING IT POSITIVE WON'T WORK

        for(int i=0; i<32; i++){
            int lastbit = num&1;

            if(lastbit != 0) count++;
            num = num>>1;
        }
        return count;
    }
};