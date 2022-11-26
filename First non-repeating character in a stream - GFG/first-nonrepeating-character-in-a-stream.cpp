//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   int count[26] = {0};
		   
		   int pos = 0;
		   string ans = "";
		   for(int i=0;i<A.size(); i++) {
		       if(count[A[i] - 'a'] ==0) {
		               ans += A[pos];
		       } else {
		           int found = 0;
		           while(pos<=i) {
		               if(count[A[pos] - 'a'] <= 1 && A[pos] != A[i]) {
		                   ans+= A[pos];
		                   found = 1;
		                   break;
		               }
                      pos++;
		           }
		           if(!found) {
		               ans+="#";
		               
		           }
		       }
		       count[A[i] - 'a']++;
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends