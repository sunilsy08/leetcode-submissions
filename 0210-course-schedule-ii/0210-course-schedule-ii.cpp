class Solution {
public:
    vector<int>toposort(vector<int>adj[], int n){
        queue<int>q;
        vector<int>ans;
        vector<int>indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]){
                if(--indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == n) return ans;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>adj[numCourses];
        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        return toposort(adj,numCourses);
    }
};