class Solution {
public:
    bool isIsomorphic(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        unordered_map<char,char>m1, m2;

        for(int i=0; i<s1.size(); i++){
            char l = s1[i];
            char r = s2[i];
            if(m1.find(l) != m1.end() && m1[l] != r){
                return false;
            }else if(m2.find(r) != m2.end() && m2[r] != l){
                return false;
            } else {
                m1[l] = r;
                m2[r] = l;
            }
        }
        return true;
    }
};