class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long mod = n <0 ? -1* (long)n : (long)n;
        long pow = mod;
        while(pow) {
            if(pow %2 == 0) {
                x = x*x;
                pow = pow/2;
            } else {
                ans = ans*x;
                pow--;
            }
        }
        if(n<0) ans = 1.0/ans;
        return ans;
    }
};