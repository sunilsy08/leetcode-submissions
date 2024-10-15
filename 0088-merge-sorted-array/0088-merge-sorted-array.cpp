class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1, right = n-1;
        int index = m+n-1;

        while(left>=0 && right >=0){
            if(nums1[left] > nums2[right]){
                nums1[index--] = nums1[left--];
            } else {
                nums1[index--] = nums2[right--];
            }
        }
        while(right >=0){
            nums1[index--] = nums2[right--];
        }
    }
};