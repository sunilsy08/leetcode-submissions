class Solution {
public:
    // Union-Find / Disjoint Set Union (DSU) structure
    class DSU {
    public:
        unordered_map<string, string> parent;
        unordered_map<string, int> rank;

        // Find with path compression
        string find(string s) {
            if (parent[s] != s) {
                parent[s] = find(parent[s]);
            }
            return parent[s];
        }

        // Union by rank
        void unionSet(string a, string b) {
            string rootA = find(a);
            string rootB = find(b);

            if (rootA != rootB) {
                if (rank[rootA] > rank[rootB]) {
                    parent[rootB] = rootA;
                } else if (rank[rootA] < rank[rootB]) {
                    parent[rootA] = rootB;
                } else {
                    parent[rootB] = rootA;
                    rank[rootA]++;
                }
            }
        }

        // Add a new element to the DSU
        void add(string s) {
            if (parent.find(s) == parent.end()) {
                parent[s] = s;
                rank[s] = 0;
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;

        // Step 1: Union emails within the same account
        for (auto& account : accounts) {
            string name = account[0];
            string firstEmail = account[1];

            for (int i = 1; i < account.size(); i++) {
                dsu.add(account[i]);  // Add email to DSU
                emailToName[account[i]] = name;  // Map email to name
                dsu.unionSet(firstEmail, account[i]);  // Union first email with current email
            }
        }

        // Step 2: Group emails by their root
        unordered_map<string, set<string>> groupedEmails;
        for (auto& emailPair : emailToName) {
            string email = emailPair.first;
            string root = dsu.find(email);
            groupedEmails[root].insert(email);
        }

        // Step 3: Format the result
        vector<vector<string>> result;
        for (auto& group : groupedEmails) {
            vector<string> account(group.second.begin(), group.second.end());
            account.insert(account.begin(), emailToName[group.first]);  // Add the name at the beginning
            result.push_back(account);
        }

        return result;
    }
};
