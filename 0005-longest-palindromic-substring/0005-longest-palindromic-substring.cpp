class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0, ans = 0;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            len = 0;
            // Odd length palindrome
            while (l >= 0 && r < n && s[l] == s[r]) {
                len = (r - l + 1);
                if (len > ans) {
                    start = l;
                    end = r;
                    ans = len;
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                len = (r - l + 1);
                if (len > ans) {
                    start = l;
                    end = r;
                    ans = len;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, ans);
    }
};
