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
    // vector<vector<int>> findLeavesHelper (TreeNode* root, vector<vector<int>> ans, Map<TreeNode*, int> m, int i){
    //     vector<int> v;
    //     if(root == NULL) return ans;
    //     findLeavesHelper(root->left, ans, m, i+1);
    //     findLeavesHelper(root->right, ans, m, i+1);
    //     if(root->left == NULL && root->right == NULL){
    //         v.push_back(root);
    //     }
    // }
    int DistanceFromLeaf(TreeNode* root,  vector<vector<int>> &ans){
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) {
            ans[0].push_back(root->val);
            return 0;
        }
        int ldist = DistanceFromLeaf(root->left, ans);
        int rdist = DistanceFromLeaf(root->right, ans);
        ans[max(ldist,rdist)+1].push_back(root->val);
        return max(ldist,rdist) + 1;
    }
    int height(TreeNode*root){
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r) + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int n = height(root);
        vector<vector<int>> ans(n);
        // vector<vector<int>> ans;
         DistanceFromLeaf(root, ans);
        return ans;
    }
};