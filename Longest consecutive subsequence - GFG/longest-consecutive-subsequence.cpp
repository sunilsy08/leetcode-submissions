//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      map<int,int>m;
      for(int i=0;i<n;i++) {
          m[a[i]]++;
      }
      int ans = INT_MIN;
      for(int i=0;i<n;i++) {
          if(m.find(a[i]-1) == m.end()) // meand that this element is beginning of a sequence
          {
              int len = 0;
              int elem = a[i];
              while(m.find(elem) != m.end()){
                 len++;
                 elem++;
              }
              ans = max(ans, len);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends