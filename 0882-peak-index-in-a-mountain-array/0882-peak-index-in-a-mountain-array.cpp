class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int low = 0;
        int high = n-1;

        int mid;
        while(low<high) {
            mid = low + (high - low)/2;
            int left = mid == 0 ? INT_MIN : arr[mid-1];
            int right = mid == n-1 ? INT_MIN: arr[mid+1];

            if(left< arr[mid] && arr[mid] > right) return mid;

            if(left < arr[mid]) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};