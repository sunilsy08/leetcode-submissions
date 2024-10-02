class Solution {
public:
   void dfs(string email,  set<string>&emails, map<string,bool>&visited, map<string,set<string>>&adj) {
            visited[email] = true;
            emails.insert(email);
            for (auto& neighbor : adj[email]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, emails, visited, adj);
                }
            }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,set<string>>adj;
        vector<vector<string>> ans;
        map<string, string>mailUser;
        map<string,bool>visited;
        int n = accounts.size();
        for(auto account: accounts){
            string user = account[0];
            for(int i=1; i<account.size(); i++){
                mailUser[account[i]] = user;  
                if (i == 1) continue;  // Skip the first email
                adj[account[i - 1]].insert(account[i]);
                adj[account[i]].insert(account[i - 1]);
            }
        }
        for(auto& email: mailUser){
            if(!visited[email.first]) {
                set<string>emails;
                dfs(email.first, emails, visited, adj);
                vector<string> account(emails.begin(), emails.end());
                account.insert(account.begin(), mailUser[email.first]);  // Insert username at the beginning
                ans.push_back(account);
            }
        }
        return ans;
    }
};