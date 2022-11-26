//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int a[], int n) {
    vector<int>left(n, INT_MAX);
    vector<int>right(n, INT_MIN);
    int leftmax = INT_MIN;
    int rightmin = INT_MAX;
    
    for(int i=1;i<n;i++) {
        leftmax = max(leftmax, a[i-1]);
        left[i] = leftmax;
    }

    for(int i = n-2; i>=0; i--) {
        rightmin = min(rightmin,a[i+1]);
        right[i] = rightmin;
    }
    for(int i=0;i<n;i++) {
        if((a[i] >= left[i] )
        && (a[i] <= right[i])
        ) return a[i];
    }
    return -1;
}