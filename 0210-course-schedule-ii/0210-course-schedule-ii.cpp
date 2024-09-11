class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        queue<int>q;
        vector<int>ans;
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);

        for(int i=0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(auto child: adj[curr]){
                if(--indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        if(ans.size() != numCourses) {
            ans.clear();
        }
        return ans;
    }
};