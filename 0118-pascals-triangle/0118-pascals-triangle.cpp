class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ns(n);
        if(n<=0)return ns;
        
        vector<int>x;
        x.push_back(1);
        ns[0]=(x);
        
        
        for(int i = 1;i<n;i++){
             vector<int>x;
            x.push_back(1);
            for(int j = 0;j<i-1;j++){
                x.push_back(ns[i-1][j] + ns[i-1][j+1]);
            }
            x.push_back(1);
             ns[i]=(x);
        }
        return ns;
    }
};