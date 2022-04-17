class Solution {
    
    
/*
Example:    h = house,  * = heater  M = INT_MAX

        h   h   h   h   h   h   h   h   h    houses
        1   2   3   4   5   6   7   8   9    index
        *           *       *                heaters
                
        0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
        0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

        0   1   1   0   1   0   1   2   3    (res = minimum of above two)

Result is maximum value in res, which is 3.
*/
    
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> ans (houses.size(), INT_MAX);
        int curr=0;
        for(int i=0; i<houses.size() && curr < heaters.size();){
            if(houses[i] <= heaters[curr]){
                ans[i] = heaters[curr] - houses[i];
                i++;
            }
           else{
                curr++;
            }
        }

        curr = heaters.size()-1;
        for(int i=houses.size()-1; i>= 0  && curr >=0; ){
            if(houses[i] >= heaters[curr]){
                ans[i] =  min(ans[i], houses[i] - heaters[curr]);
                i--;
            }
            else{
                curr--;
            }
        }

        int x = *max_element(ans.begin(), ans.end());
        
        return x;
        
    }
};