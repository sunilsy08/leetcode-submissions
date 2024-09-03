class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for(auto it: adj[course]){
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};