class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;

        map<char, int>m1,m2;
        for(int i=0; i<s1.size(); i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        int matches = 0;
        for(char ch = 'a'; ch <='z'; ch++){
            if(m1[ch] == m2[ch]){
                matches++;
            }
        }
        if(matches == 26) return true;
        int l=0,r=n1;
        
        while(r<n2){
            if(matches == 26) return true;
            char chl = s2[l];
            char chr = s2[r];
            m2[chr]++;
            if(m2[chr] == m1[chr]){
                matches++;
            } else if(m2[chr] == m1[chr] + 1){
                matches--;
            }

            m2[chl]--;
            if(m2[chl] == m1[chl]){
                matches++;
            } else if(m2[chl] == m1[chl]-1){
                matches--;
            }
            l++;
            r++;
        }
        return matches == 26;
    }
};