//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        stack<int>st;
        int visited[N] = {0};
        for(int i=0;i<N;i++) {
            if(!visited[i]) {
                topoSort(i,adj,visited,st);
            }
        }
        int source = 0;
        vector<int>ans(N,1e9);
        ans[0] = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            
            for(auto it: adj[u]) {
                int v = it.first;
                int wt = it.second;
                if(ans[u] + wt < ans[v]) {
                    ans[v] = wt + ans[u];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (ans[i] == 1e9) ans[i] = -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends