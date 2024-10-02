class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    // Generate quadruplets
    for (int i = 0; i < n; i++) {
      
        // Skip duplicates for i
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for j
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;

            // Two pointers approach
            while (k < l) {
                long long sum = (long)arr[i] + (long)arr[j] + (long)arr[k] + (long)arr[l];
                if (sum == target) {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    // Skip duplicates for k and l
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return res;
}
};