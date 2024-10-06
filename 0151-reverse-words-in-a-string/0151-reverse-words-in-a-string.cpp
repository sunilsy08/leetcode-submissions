class Solution {
public:
    void reverse(string& s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

    string reverseWords(string s) {
        int l = 0, r = 0;
        int n = s.size();
        string ans = "";
        while (l <= n) {
            while (l < n && s[l] == ' ') l++;
            if (l == n) break;

            r = l+1;
            while (r < n && s[r] != ' ') r++;
            string word = s.substr(l,r-l);
            reverse(word, 0, word.size()-1);
            if(ans == ""){
                ans += word;
            }else {
                ans += " ";
                ans += word;
            }
            l = r + 1;
        }
        reverse(ans, 0, ans.size()-1);
        return ans;
    }
};