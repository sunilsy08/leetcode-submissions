class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>&safe,
    vector<bool>&visited, vector<bool>&pathvisited
    ) {
        visited[node] = true;
        pathvisited[node] = true;

        for(auto it: graph[node]) {
            if(!visited[it]) {
                if(dfs(it, graph, safe, visited, pathvisited)){
                    safe[node] = false;
                    return true;
                }
            } else {
                if(pathvisited[it]){
                    safe[node] = false;
                    return true;
                }
            }
        }
        safe[node] = true;
        pathvisited[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>safe(n, false);
        vector<bool>visited(n, false);
        vector<bool>pathvisited(n, false);
        vector<int>ans;


        for(int i=0; i<n; i++) {
            if(!visited[i]){
                dfs(i, graph, safe, visited, pathvisited);
            }
        }

        for(int i=0; i<n; i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};