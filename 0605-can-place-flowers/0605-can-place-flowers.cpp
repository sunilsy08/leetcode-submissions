class Solution {
public:
    int helper(vector<int>& flowerbed, int i, int n){
        if(i >= flowerbed.size()) return 0;
        if(i < 0) return 0;
        int ans = 0;
        bool isLeftFlower = i == 0 ? false : flowerbed[i-1] == 1;
        bool isRightFlower = i == flowerbed.size()-1 ? false : flowerbed[i+1] == 1;
        int l=0,r=0;
        if(!isLeftFlower && !isRightFlower && flowerbed[i] == 0){
            flowerbed[i] = 1;
            l = 1 + helper(flowerbed, i+2, n);
        }
        r = helper(flowerbed, i+1, n);
        if(l>=r) cout<<" l > r \n";
        else cout<<" r > l \n";
        return max(l,r);
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        // return helper(flowerbed, 0, n) >= n;

        for(int i=0; i<flowerbed.size(); i++){
            bool leftFlower = i==0?false: flowerbed[i-1] == 1;
            bool rightFlower = i == flowerbed.size()-1? false: flowerbed[i+1] == 1;

            if(flowerbed[i] == 0 && !leftFlower && !rightFlower){
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >=n;
    }
       
};