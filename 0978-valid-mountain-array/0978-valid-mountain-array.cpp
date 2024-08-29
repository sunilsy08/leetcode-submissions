class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, n = arr.size();
        bool found = false;
        if (n < 3) return false; // A valid mountain array must have at least 3 elements
        
        // Ascend until the peak
        while (l < n - 1 && arr[l] < arr[l + 1]) {
            l++;
        }
        // Peak cannot be at the start or end
        if (l == 0 || l == n - 1) return false;
        // Descend until the end
        while (l < n - 1 && arr[l] > arr[l + 1]) {
            l++;
        }
        // Check if we reached the end of the array
        return l == n - 1;
    }
};