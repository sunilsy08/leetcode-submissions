//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkcycle(int V, vector<int> adj[], bool visited[], int node, int parent) {
        // if(visited[node]) return true;
        visited[node] = true;
        bool ans = false;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(checkcycle(V, adj, visited, it, node))
                 return true;
            } else if(it!= parent) {
                return true;
            }
        }
        return ans;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V] = {false};
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(checkcycle(V,adj,visited,i, -1))
                return true;
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