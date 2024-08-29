class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, n = arr.size();
        bool found = false;
        if (n < 3) return false;
        
        while (l < n - 1 && arr[l] < arr[l + 1]) {
            l++;
        }
        // Peak cannot be at the start or end
        if (l == 0 || l == n - 1) return false;
        // Descend until the end
        while (l < n - 1 && arr[l] > arr[l + 1]) {
            l++;
        }
        return l == n - 1;
    }
};