//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool possible(int a[], int n, int low,int mid,int high, int m) {
        
        int students = 1;
        long pages = 0;
        for(int i=0; i<n; i++) {
            if(a[i] > mid) return false; // If any page is greater than out current barrier (mid), return false
            // as no child should be allocated more pages than barrier.
            
            if(a[i] + pages > mid) {
                pages = a[i];
                students++;
            } else{
                pages += a[i];
            }
        }
        if( students > m) return false;
        return true;
    }
    int getMin(int a[], int n) {
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            ans = min(ans, a[i]);
        }
        return ans;
    }
    int sum(int a[], int n) {
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += a[i];
        }
        return ans;
    }
    
    int findPages(int a[], int n, int m) 
    {
        if(m>n) return -1;
        
        int low = getMin(a,n);
        int high = sum(a,n);
        
        int mid;
        int ans = -1;
        while(low<=high) {
            mid = low + (high - low)/2;
            
            if(possible(a,n,low,mid,high, m)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends