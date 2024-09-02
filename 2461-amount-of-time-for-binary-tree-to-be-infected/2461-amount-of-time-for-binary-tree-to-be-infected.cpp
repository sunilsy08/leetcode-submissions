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
    void fillAdjacencyList(TreeNode* root, unordered_map<int, unordered_set<int>> &adj) {
        if(root == NULL) return;
        if(root->left){
            adj[root->val].insert(root->left->val);
            adj[root->left->val].insert(root->val);
            fillAdjacencyList(root->left, adj);
        }
        if(root->right){
            adj[root->val].insert(root->right->val);
            adj[root->right->val].insert(root->val);
            fillAdjacencyList(root->right, adj);
        }
    }
    void printAdjacencyList(unordered_map<int, unordered_set<int>> adj){
        for (const auto& pair : adj) {
            int node = pair.first;
            const unordered_set<int>& neighbors = pair.second;

            cout << node << ": ";
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> adj;
        fillAdjacencyList(root,adj);
        queue<pair<int,int>>q;
        unordered_set<int>burnt;

        q.push({start,0});
        burnt.insert(start);
        int maxtime = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            maxtime = max(maxtime, time);
            q.pop();
            for(auto it: adj[node]){
                if(burnt.find(it) == burnt.end()) {
                    q.push({it,time+1});
                    burnt.insert(it);
                }
            }
        }

        return maxtime;
    }
};