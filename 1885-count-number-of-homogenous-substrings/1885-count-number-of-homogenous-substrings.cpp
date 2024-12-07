class Solution {
public:
    int countHomogenous(string s) {
        int i =0 ;
        int MOD = 1e9 + 7;
        int ans = 0;
        while(i < s.size()) {
            char ch = s[i];
            int count = 0;
            while(i <s.size() && s[i] == ch) {
                count++;
                i++;
            }
            ans = ans + (((long)count * ((long)count + 1))/2) % MOD;
        }
        return ans;
    }
};