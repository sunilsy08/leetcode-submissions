class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2) return false;

        map<char, int>m1,m2;
       for(int i=0;i<n1;i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        int matches =0;
        for(char ch = 'a'; ch<='z'; ch++) {
            if(m1[ch] == m2[ch]){
                matches++;
            }
        }
        if(matches == 26) return true;

        int l =0, r=n1;

while (r < n2) {
            if (matches == 26) return true;

            char chl = s2[l];
            char chr = s2[r];

            // Sliding window - add new character
            m2[chr]++;
            if (m2[chr] == m1[chr]) {
                matches++;
            } else if (m2[chr] == m1[chr] + 1) {
                matches--;
            }

            // Sliding window - remove old character
            m2[chl]--;
            if (m2[chl] == m1[chl]) {
                matches++;
            } else if (m2[chl] == m1[chl] - 1) {
                matches--;
            }

            l++;
            r++;
        }

        while(r<n2){
            if(matches == 26) return true;
            char chl = s2[l];
            char chr = s2[r];
            m2[chl]--;
            if(m2[chl] == m1[chl]) {
                matches++;
            } 
            // NOTE THAT WE CAN"T SIMPLY WRITE THIS IN ELSE BLOCK. MADE THIS MISTAKE :)
            else if (m2[chl] + 1 == m1[chl]){
                matches--;
            }

            // ALSO, we can't perform m2[chr]++, m2[chl]-- together. We need to update corrersponding matches first before moving to next.
            m2[chr]++;
            if(m2[chr] == m1[chr]){
                matches++;
            } 
            // SAME HERE
            else if (m2[chr] == m1[chr]+1){
                matches--;
            }
            l++;
            r++;
        }
        return matches==26;
    }
};