class Solution {
public:
    bool check(string & str1, string & str2) {
        int l1 = str1.size();
        int l2 = str2.size();
        if(l1 > l2) return false;

        int l = 0, r =0;
        while(l < l1) {
            if(str1[l] != str2[r]) return false;
            l++;
            r++;
        }
        l = l1-1;
        r = l2-1;
        while(l>=0) {
            if(str1[l] != str2[r]) return false;
            l--;
            r--;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if(check(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};