class Solution {
public:
    vector<int>generateNthRow(int n) {
        int ans = 1;
        vector<int>row;
        row.push_back(ans);
        for(int i=1;i<n;i++) {
            ans = ans* (n-i);
            ans = ans/ (i);
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(generateNthRow(i));
        }
        return ans;
    }
};