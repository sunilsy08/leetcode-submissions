class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
//      This will represent distance from 0
        vector<int>dist(n,n-1);

        vector<int>adj[n];
        vector<int>ans;

        for(int i=0; i<n-1; i++) {
            adj[i].push_back(i+1);
            dist[i] = i;
        }

        for(auto query : queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);

            queue<pair<int,int>>q;
            q.push({u, dist[u]});

            while(!q.empty()) {
                int node = q.front().first;
                int d = q.front().second;
                q.pop();

                dist[node] = min(dist[node], d);

                for(auto nxt : adj[node]) {
                    if(dist[nxt] > d+1) {
                        q.push({nxt, d+1});
                    }
                }
            }

            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};