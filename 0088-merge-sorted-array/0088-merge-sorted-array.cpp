class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int r = n-1;
        int l = m-1;
        
        int index = m+n-1;
        while(r>=0 || l>=0 ) {
            if(r<0) nums1[index--] = nums1[l--];
            else if(l<0) nums1[index--] = nums2[r--];
            else if(nums2[r] > nums1[l]) nums1[index--] = nums2[r--];
            else nums1[index--] = nums1[l--]; 
        }
    }
};