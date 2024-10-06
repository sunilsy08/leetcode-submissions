class Solution {
public:
    int xdel[4] = {0, -1, 0, 1};
    int ydel[4] = {1, 0, -1, 0};
    bool isRobotBounded(string instructions) {
        int currFace = 0;
        int x =0,y=0;

        while(true){
            for(char command : instructions){
                if(command == 'G'){
                    x = x+ xdel[currFace];
                    y = y+ ydel[currFace];
                } else if(command == 'L'){
                    currFace +=1;
                    currFace %=4;
                } else {
                    currFace -=1;
                    if(currFace == -1){
                        currFace =3;
                    }
                }
            }
            if(x == 0 && y==0) return true;
            if(currFace == 0) return false;
        }
        
        return false;
    }
};