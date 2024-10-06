class Solution {
public:
    bool checkValidString(string s) {
        unsigned opencount = 0;
        unsigned starcount = 0;
        unsigned closecount = 0;
        int l=0;
        while(l<s.size()){
            if(s[l] == '('){
                opencount++;
            } else if(s[l] == '*'){
                starcount++;
            } else {
                closecount++;
                if(closecount > opencount){
                    if(starcount == 0){
                        return false;
                    } else {
                        starcount--;
                        opencount++;
                    }
                }
            }
            l++;
        }
        return opencount == closecount;
    }
};