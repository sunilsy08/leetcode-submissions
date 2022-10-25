//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node, vector<int>adj[], bool visited[]) {
        visited[node] = true;
        
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,adj,visited);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>aj[V+1];
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                if(adj[i][j] ==1 && i!=j) {
                    aj[i+1].push_back(j+1);
                    aj[j+1].push_back(i+1);
                }
            }
        }
        bool visited[V+1] = {false};
        int count = 0;
        for(int i=1;i<=V;i++) {
            if(!visited[i]) {
                dfs(i,aj,visited);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends