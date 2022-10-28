//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<int>adj[], int visited[], stack<int>&st) {
	    visited[node] = true;
	    
	    for(auto it: adj[node]) {
	        if(!visited[it]) {
	            dfs(it, adj, visited, st);
	        }
	    }
	    st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	   /* FOR DFS ALGO */
	   // stack<int>st;
	   // int visited[V] = {0};
	    
	   // for(int i=0;i<V;i++) {
	   //     if(!visited[i]) {
	   //         dfs(i,adj,visited,st);
	   //     }
	   // }
	   // vector<int>ans;
	   // while(!st.empty()) {
	   //     ans.push_back(st.top());
	   //     st.pop();
	   // }
	   // return ans;
	   
	   
	   /* FOR KAHN'S ALGORITHM*/
	   return kahns_algo_bfs(V, adj);

	   
	}
	
		
	vector<int> kahns_algo_bfs(int V, vector<int> adj[]) {
	   int indegree[V] = {0};
	   for(int i=0;i<V;i++) {
	       int count = 0;
	       for(auto it: adj[i]) {
	           indegree[it] ++;
	       }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++) {
	       if(indegree[i] == 0) {
	           q.push(i);
	       }
	   }
	    vector<int>ans;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adj[node]) {
	            if(--indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends