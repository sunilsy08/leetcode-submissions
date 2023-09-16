class Solution {
public:


/* Approach 1: This will work only when input is like this:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
i.e, we are already given extra space in nums1

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

    */
/*However, when input is like  [1,2,3] [2,5,6] and output : [1,2,2] [3,5,6]
Below two approached will be used.
*/

     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1;
        int r = 0;

        while (l>=0 && r<n) {
            if (nums1[l] > nums2[r]) {
                swap(nums1[l--], nums2[r++]);
            } else {
                break;
            }
        }
        sort(&nums1[0], &nums1[m]);
        sort(nums2.begin(),  nums2.end());
        for(int i=0;i<n;i++) {
            nums1[m+i] = nums2[i];
        }
    }

};