//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    // n = eggs
    // k = floors
    int helper(int n, int k, int* max_el) {
         if(n <= 0 || k<=0) return 0;
         if(k == 1) return 1;
        if(n == 1) return k;
        
        
        int mins = INT_MAX;
        for(int i=1;i<=k;i++) {
            int res = max(helper(n-1,i-1, max_el), helper(n,k-i, max_el));
            
            mins = min(mins, res);
        }
        *max_el = min(*max_el, mins);
        return mins +1;
    }
    int dp_helper(int n, int k, vector<vector<int>> &v, int * max_el) {
        if(v[n][k] != -1) return v[n][k];
        if(k == 0 || k == 1) {
            v[n][k] = k;
            return v[n][k];
        }
        if(n == 1) {
            v[n][k] = k;
            return v[n][k];
        }
        int ans = INT_MAX;
        for(int i=2;i<=k; i++) {
            int res = max(dp_helper(n-1,i-1,v,max_el), dp_helper(n, k-i, v,max_el));
            ans = min(ans, res);
        }
        
        v[n][k] = ans+1;
        return v[n][k];
        
        
    }
    int eggDrop(int n, int k) 
    {
    vector<vector<int>>v(n+1,vector<int>(k+1, -1));
        int ans = 0;
    //   return helper(n,k,&ans);
    return dp_helper(n,k,v,&ans);
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends