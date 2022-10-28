//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node, vector<int>adj[], int vis[], int pathVis[], int check[]) {
      vis[node] = 1;
      pathVis[node] = 1;
    //   check[node] = 0;
      for(auto it: adj[node]) {
          if(!vis[it]) {
              if(dfs(it,adj,vis,pathVis,check)) {
                  check[node] = 0;
                  return true;
              }
              
          }else {
                  if(pathVis[it]) {
                      check[node] = 0;
                      return true;
                  }
              }
      }
      pathVis[node] = 0;
      check[node] = 1;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int visited[V] = {0};
        int pathVisited[V] = {0};
        int check[V] = {0};
        vector<int>ans;
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfs(i,adj,visited,pathVisited,check);
            }
        }
        for(int i=0;i<V;i++) {
            if(check[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends