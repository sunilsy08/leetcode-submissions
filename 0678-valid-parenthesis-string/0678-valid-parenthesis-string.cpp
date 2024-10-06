class Solution {
public:
    bool checkValidString(string s) {
        int opencount = 0;
        int starcount = 0;
        int closecount = 0;
        int l=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '*'){
                opencount++;
            } else {
                opencount--;
            }
            if(opencount <0) return false;
        }
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ')' || s[i] == '*'){
                closecount++;
            } else {
                closecount--;
            }
            if(closecount <0) return false;
        }
        return true;
    }
};