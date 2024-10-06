class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>adj[2][n];
        // vector<bool>visited[2];
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        vector<int>ans(n, -1);
        // vector<int>redAdj[n];
        queue<pair<int,pair<int,int>>>q;
        for(int i=0; i<redEdges.size(); i++){
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adj[0][u].push_back(v);
            // if(u == 0){
            //     q.push({0,{0, 0}});
            //     visited[0][0] = true;
            // }
        }
        for(int i=0; i<blueEdges.size(); i++){
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adj[1][u].push_back(v);
            // if(u == 0){
            //     q.push({0,{0, 1}});
            //     visited[1][0] = true;
            // }
        }
        q.push({0, {0, 0}}); 
        q.push({0, {0, 1}}); 
        visited[0][0] = visited[1][0] = true;


        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second.first;
            int color = q.front().second.second;
            q.pop();
            if(ans[node] == -1){
                ans[node] = dist;
            }
            color = (color + 1) %2;
            for(auto it: adj[color][node]){
                if(!visited[color][it]){
                    visited[color][it] = true;
                    q.push({it, {dist+1, color}});
                }
            }
        }
        return ans;
    }
};