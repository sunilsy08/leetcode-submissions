/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fillAdjacencyList(TreeNode* root, unordered_map<int, vector<int>> &adj) {
        if (root == nullptr) return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            fillAdjacencyList(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            fillAdjacencyList(root->right, adj);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        fillAdjacencyList(root, adj);
        
        queue<pair<int, int>> q;
        unordered_set<int> burnt;

        q.push({start, 0});
        burnt.insert(start);
        int maxTime = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            maxTime = max(maxTime, time);

            for (int neighbor : adj[node]) {
                if (burnt.find(neighbor) == burnt.end()) {
                    q.push({neighbor, time + 1});
                    burnt.insert(neighbor);
                }
            }
        }

        return maxTime;
    }
};
