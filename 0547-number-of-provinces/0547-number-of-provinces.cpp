class Solution {
public:

    void dfs(bool visited[], vector<int> adj[], int node) {
        visited[node] = true;

        for(auto it: adj[node]) {
            if(!visited[it]){
                dfs(visited, adj, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool visited[n+1];
        memset(visited, false, sizeof(visited));
        vector<int> adj[n+1];

        for(int i=0; i <n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int count = 0;
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfs(visited, adj, i);
                count++;
            }
        }
        return count;
    }
};