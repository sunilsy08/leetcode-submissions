class Solution {
public:
    int getval(char c) {
        return c - 'A' + 1; // Convert character to corresponding number (A = 1, B = 2, ..., Z = 26)
    }
    int titleToNumber(string columnTitle, int ind = 0) {
        int n = columnTitle.size();
        if(n-1 == ind) return getval(columnTitle[ind]);

        int curr = getval(columnTitle[ind]);
        int mul = pow(26, n - ind - 1);
        curr *= mul;
        curr += titleToNumber(columnTitle, ind+1);
        return curr;
    }
};