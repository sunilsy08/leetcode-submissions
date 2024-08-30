class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        char prev = 'a';
        int currlen = 0;
        int ans = 0;
        map<char, int>m;
        
        for(int i=0; i<n; i++) {
            if(word[i] >= prev) {
                currlen++;
                m[word[i]]++;
                prev = word[i];
            } else {
                m['a'] = 0;
                m['e'] = 0;
                m['i'] = 0;
                m['o'] = 0;
                m['u'] = 0;
                m[word[i]]++;
                prev = word[i];
                currlen=1;
            }
            if(m['a'] > 0 && m['e'] >0 && m['i']
                 && m['o'] > 0 && m     ['u'] >0) {
                    ans = max(ans,currlen);
                }
        }
        return ans;
    }
};