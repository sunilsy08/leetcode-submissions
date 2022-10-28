//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, int V, vector<int>adj[], bool visited[], bool pathVisited[]) {
        visited[node] = true;
        pathVisited[node] = true;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(dfs(it, V, adj, visited, pathVisited)) {
                    return true;
                }
            } else {
                if(pathVisited[it] ) {
                    return true;
                }
            }
        }
        pathVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        /* CYCLE DETECTION USING DFS
        bool visited[V] = {false};
        bool pathVisited[V] = {false};
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                if(dfs(i,V,adj,visited,pathVisited)) {
                    return true;
                }
            }
        }
        return false; */
        
        
        // CYCLE DETECTION USING KAHN'S ALGO BFS
        
        int inorder[V] = {0};
        
        for(int i=0;i<V;i++) {
            for(auto it: adj[i]) {
                inorder[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++) {
            if(inorder[i] == 0) {
                q.push(i);
            }
        }
        int count =0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto it:adj[node]) {
                if(--inorder[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(count == V) return false;
        return true;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends