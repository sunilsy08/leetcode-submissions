class Solution {
public:
    int numberOfChild(int n, int k) {
        int roundTime = n-1;
        int completeRounds = k/roundTime;
        int direction;
        int start; 
        if(completeRounds%2 == 1){
            start = n-1;
            direction = -1;
        } else {
            start = 0;
            direction = 1;
        }
        return start + (k%roundTime)*direction;
    }
};