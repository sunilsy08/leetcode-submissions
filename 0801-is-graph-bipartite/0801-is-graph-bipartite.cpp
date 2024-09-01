class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, -1);
        for(int i=0; i<n; i++) {
            if(visited[i] == -1){
                int color = 0;
                queue<pair<int, int>>q;
                q.push({i,color});
                while(!q.empty()) {
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(auto it: graph[node]){
                        if(visited[it] == col) return false;
                        else if(visited[it] == -1){
                            visited[it] = !col;
                            q.push({it, !col});
                        }
                    }
                }
            }
        }
        
        return true;
    }
};