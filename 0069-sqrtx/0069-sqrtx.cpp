class Solution {
public:
    int mySqrt(int x) {
        int l=1, r =x/2+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid == x/mid) return mid;
            if(x/mid > mid){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return r;
    }
};