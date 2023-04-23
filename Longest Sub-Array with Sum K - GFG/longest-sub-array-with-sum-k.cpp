//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int sum = 0, maxlen = 0, index = 0;
        map<int, int>m;
        
        for(int i=0;i<n;i++) {
            sum+= a[i];
            if(sum == k) {
                maxlen = i+1;
            }  
                        
            if(m.find(sum) == m.end()) {
                m[sum] = i;
            }
            if (m.find(sum-k) != m.end()) {
                index = m[sum-k];
                maxlen = max(maxlen, i-index);
            }

        }
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends