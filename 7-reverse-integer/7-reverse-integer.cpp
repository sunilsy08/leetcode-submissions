class Solution {
public:
    int reverse(int x) {
        if(x>INT_MAX)
            return 0;
        if(x/10 == 0 )
            return x;
        int mul = x<0 ? -1:1;
        
        long int ans =0;
        int z = abs(x);
        while(z>0){
            ans = ans*10 + (z%10);
            z/=10;
        }
        
        ans =  ans*mul;
        
        if(ans>INT_MAX || ans<INT_MIN){
            return 0;
        }
        return ans;
    }
};