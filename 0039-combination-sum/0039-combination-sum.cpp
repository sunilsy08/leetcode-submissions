class Solution {
public:
    bool helper(vector<int>& candidates, int ind, int currsum, int target, vector<vector<int>>& ans, vector<int>& curr) {
        // Base condition: If current sum exceeds target, return false (no need to explore further)
        if (currsum > target) return false;

        // If the current sum matches the target, we found a valid combination
        if (currsum == target) {
            ans.push_back(curr);
            return true;
        }

        // Traverse the candidates starting from index `ind`
        for (int i = ind; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]); // Include the current candidate

            // Recursive call: Stay on the same index (i) since we can reuse the same element
            helper(candidates, i, currsum + candidates[i], target, ans, curr);
            
            // Backtrack: Remove the last element to explore the next option
            curr.pop_back();
        }

        return false;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, 0, 0, target, ans, curr);
        return ans;
    }
};
