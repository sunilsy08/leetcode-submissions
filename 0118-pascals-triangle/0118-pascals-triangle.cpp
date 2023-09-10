class Solution {
public:
    vector<int>generateNthRow(int n) {
        int ans = 1;
        vector<int>row;
        row.push_back(ans);
        for(int i=1;i<n;i++) {
            ans = ans* (n-i);
            ans = ans/ (i);
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(generateNthRow(i));
        }
        return ans;
    }
    
//     ANOTHER ALTERNATIVE WAY: 
//         vector<vector<int>> generate(int n) {
//         vector<vector<int>>ns(n);
//         if(n<=0)return ns;
        
//         vector<int>x;
//         x.push_back(1);
//         ns[0]=(x);
        
        
//         for(int i = 1;i<n;i++){
//              vector<int>x;
//             x.push_back(1);
//             for(int j = 0;j<i-1;j++){
//                 x.push_back(ns[i-1][j] + ns[i-1][j+1]);
//             }
//             x.push_back(1);
//              ns[i]=(x);
//         }
//         return ns;
//     }
};