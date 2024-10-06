class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s == goal) return true;
        for(int i=0; i<n; i++){
            char ch = s[0];
            s = s.substr(1,n-1) + ch;
            if(s == goal) return true;
        }   
        return false;
    }
};