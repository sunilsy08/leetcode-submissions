class Solution {
public:
    // int helper(vector<int>& flowerbed, int ind, int n){
    //     if(ind==n) return 0;
    //     if(n == 1) return flowerbed[0] == 0 ? 1: 0;
        
    //     for(int i=0; i<n; i++){

    //     }
    // }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        // count = helper(flowerbed,0,flowerbed.size());
        for(int i=0; i<flowerbed.size(); i++){
            bool isLeftFlower = i-1 < 0 ? false: flowerbed[i-1] == 1;
            bool isRightFlower = i+1 >=flowerbed.size() ? false: flowerbed[i+1] == 1;

            if(flowerbed[i] == 0 && !isLeftFlower && !isRightFlower){
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >=n;
    }
};