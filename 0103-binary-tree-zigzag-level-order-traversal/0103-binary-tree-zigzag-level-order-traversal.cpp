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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        bool forwardInsertion = true;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n);
            int count = 0;
            while(count<n){
                TreeNode*front = q.front();
                q.pop();
                if(forwardInsertion){
                    temp[count++] = front->val;
                } else {
                    temp[--n] = front->val;
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            forwardInsertion = !forwardInsertion;
            ans.push_back(temp);
        }
        return ans;
    }
};