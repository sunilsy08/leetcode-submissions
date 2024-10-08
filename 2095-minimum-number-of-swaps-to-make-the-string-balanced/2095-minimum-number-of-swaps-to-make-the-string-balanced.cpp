class Solution {
public:
    int minSwaps(string s) {
        int openCount = 0;

        for(char bracket : s){
            if(bracket == '['){
                openCount++;
            } else {
                if(openCount > 0){
                    openCount--;
                }
            }
        }
        return (openCount + 1)/2;
    }
};