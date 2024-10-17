class Solution {
public:
    void reduceAlpha(string &s, int left, int right){
        while(left <= right){
            if(s[left] == 'a'){
                s[left++] = 'z';
            } else {
                s[left++]--;
            }
        }
    }
    string smallestString(string s) {
        int left = 0, curr = 0;
        bool operationPerformed = false;

        while(curr < s.size() && !operationPerformed){
            if(s[curr] == 'a'){
                if(curr != 0){
                    reduceAlpha(s, left, curr-1);
                    operationPerformed = true;
                } else {
                    while(left < s.size() && s[left] == 'a'){
                        left++;
                    }
                    if(left == s.size()) break;
                    curr = left;
                }
            } else {
                curr++;
            }
        }

        if(curr == s.size()){
            operationPerformed = true;
            reduceAlpha(s, left, curr-1);
        }
        if(!operationPerformed){
            s[s.size()-1] = 'z';
        }
        return s;
    }
};