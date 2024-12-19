class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxseen = 0;
        int chunks = 0;

        for(int i=0; i<arr.size(); i++) {
            maxseen = max(maxseen, arr[i]);
            if(maxseen == i){
                chunks++;
            } 
        }
        return chunks;
    }
};