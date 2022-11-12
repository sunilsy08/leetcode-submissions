//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int currencies[10] =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
  
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        
        int pos = 9;
        
        while(pos>=0) {
            if(N - currencies[pos] >=0) {
                ans.push_back(currencies[pos]);
                N-= currencies[pos];
            } else {
                pos--;
            }
            if(N == 0){
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends