//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxDP(int *arr, int n) {
	    if(n == 0 ) return 0;
	    if(n == 1) return arr[0];
	    if(n == 2) return max(arr[0],arr[1]);
	    int dp[n+1] = {0};
	    dp[0] = 0;
	    dp[1] = arr[0];
	    dp[2] = max(arr[0],arr[1]);
	    
	    for(int i=2;i<=n;i++) {
	        int opt1 = arr[i-1] + dp[i-2];
	        int opt2 = dp[i-1];
	        dp[i] = max(opt1, opt2);
	    }
	    return dp[n];
	}
	int findMaxSum(int *arr, int n) {
	   // if(n == 0 ) return 0;
	   // if(n == 1) return arr[0];
	   // if(n == 2) return max(arr[0],arr[1]);
	    
	   // int opt1 = arr[n-1] + findMaxSum(arr,n-2);
	   // int opt2 = findMaxSum(arr,n-1);
	    
	   // return max(opt1,opt2);
	   return findMaxDP(arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends