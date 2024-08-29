class Solution {
public:
    int getval(char c) {
        return c - 'A' + 1; 
    }
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            result = result * 26 + getval(columnTitle[i]);
        }
        
        return result;
    }
};