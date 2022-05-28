class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       map<char, bool> m;
        for(int i=0;i<jewels.length(); i++)
            m[jewels[i]] = true;
        
        int len =0;
        for(int i=0; i< stones.length(); i++){
            if(m[stones[i]])
                len++;
        }
        return len;
    }
};