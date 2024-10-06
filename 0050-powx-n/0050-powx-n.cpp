class Solution {
public:
    double getPower(double x, int n){
        if(n == 1) return x;
        if(n == 0) return 1;

        if(n%2 == 0){
            return getPower(x*x, n/2);
        }
        return x*getPower(x*x,n/2);
    }
    double myPow(double x, int n) {
        bool neg = n<0 ? true : false;
        if(n == 0) return 1;
        double ans = getPower(x, abs(n));
        if(neg){
            return 1/ans;
        }
        return ans;

    }
};