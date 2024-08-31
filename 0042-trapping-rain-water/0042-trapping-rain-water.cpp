class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l[n], r[n];
        int leftmax = 0, rightmax=0;
        l[0] = height[0];
        r[n-1] = height[n-1];
        for(int i=1; i<n; i++) {
            l[i] = max(l[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--) {
            r[i] = max(r[i+1], height[i]);
        }
        int water =0;
        for(int i=0; i<n; i++) {
            int diff = min(r[i], l[i]) - height[i];
            if(diff>0){
                water += diff;
            }
        }
        return water;
    }
};