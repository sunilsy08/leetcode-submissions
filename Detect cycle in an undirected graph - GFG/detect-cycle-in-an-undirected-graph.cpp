//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node, vector<int>adj[], bool visited[], int parent) {
        visited[node] = true;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(checkCycle(it,adj,visited,node)) return true;
            } else {
                if(it!=parent) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       bool visited[V] = {false};
       
       for(int i=0;i<V;i++) {
           if(!visited[i]) {
               if(checkCycle(i, adj,visited, -1)) return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends