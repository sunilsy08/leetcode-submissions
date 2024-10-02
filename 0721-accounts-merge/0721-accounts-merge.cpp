class Solution {
public:
    class DSU {
    public:
        unordered_map<string, string> parent;

        // Find with path compression
        string find(string s) {
            if (parent[s] != s) {
                parent[s] = find(parent[s]);
            }
            return parent[s];
        }

        // Union operation
        void unionSet(string a, string b) {
            string rootA = find(a);
            string rootB = find(b);
            if (rootA != rootB) {
                parent[rootA] = rootB;  // Union: link rootA to rootB
            }
        }

        // Initializes a node if it does not exist
        void add(string s) {
            if (parent.find(s) == parent.end()) {
                parent[s] = s;
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
                if (i > 1) {
                    dsu.unionSet(account[i], account[i - 1]);  // Union current email with the previous one
                }
            }
        }

        // Step 2: Group emails by their root
        unordered_map<string, vector<string>> groupedEmails;
        for (auto& emailPair : emailToName) {
            string email = emailPair.first;
            string root = dsu.find(email);
            groupedEmails[root].push_back(email);
        }

        // Step 3: Construct the final result
        vector<vector<string>> result;
        for (auto& group : groupedEmails) {
            vector<string> account = group.second;
            sort(account.begin(), account.end());  // Sort emails
            account.insert(account.begin(), emailToName[group.first]);  // Insert username at the beginning
            result.push_back(account);
        }

        return result;
    }
};
