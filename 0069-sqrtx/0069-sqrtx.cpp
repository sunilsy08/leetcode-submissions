class Solution {
public:
    int mySqrt(int x) {
        int l=1, r =x;
        int ans;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(x/mid >= mid){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};