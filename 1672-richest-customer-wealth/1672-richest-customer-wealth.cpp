class Solution {
public:
    
    int maxWealth(vector<vector<int>>a, int i, int &max){
        if(i >= a.size()) return max;
        int x = maxWealth(a,  i+1, max);
        int sum = 0;
        for(int j=0;j<a[0].size();j++)
            sum += a[i][j];
        if(sum >= max){
            max = sum;
        }
        return max;
    }
    int maximumWealth(vector<vector<int>>& accounts) {
        int x = INT_MIN;
        return maxWealth(accounts, 0, x);
    }
};