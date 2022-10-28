//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
	    int indegree[V] ={0};
	    vector<int>adj[V];
	    for(int i=0;i<prerequisites.size();i++) {
	        pair<int,int> p = prerequisites[i];
	        indegree[p.first]++;
	        adj[p.second].push_back(p.first);
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        count++;
	        
	        for(auto it: adj[node]) {
	            indegree[it]--;
	            if(indegree[it] ==0) {
	                q.push(it);
	            }
	        }
	    }
	    
	    return count == V;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends