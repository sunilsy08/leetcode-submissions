class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        unordered_map<char, int>m1;
        for(char ch: t){
            m1[ch]++;
        }
        int need =m1.size();
        int have = 0;
        int l=0,r=0;
        int maxlen = INT_MAX, maxl=0, maxr=0;
        string maxstring = "";
        unordered_map<char, int>m2;
        while(r<s.size()){
            char ch = s[r];
            m2[ch]++;
            if(m2[ch] == m1[ch]){
                // cout<<"matched: "<<m2[ch] << " "<<ch<<" ";
                have++;
                // cout<<"have: "<<have<<" Need:"<< need<<"\n";
                if(have == need){
                    while(have == need && l<=r){
                        if(maxlen > r-l+1){
                            maxlen = r-l+1;
                            maxl = l;
                            maxr = r;
                        }
                        m2[s[l]]--;
                        if(m2[s[l]] < m1[s[l]]){
                            have--;
                        }
                        l++;
                    }
                }
            }
            r++;
        }
        if(maxlen ==INT_MAX) return "";
        // cout<<maxl<<":"<<maxr;
        // cout<<"maxlen: "<<maxlen;
        return s.substr(maxl, maxlen);
        return "";
    }
};