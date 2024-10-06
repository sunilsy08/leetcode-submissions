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
    int getHeight(TreeNode*root){
        if(root == NULL) return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return 1 + max(lh,rh);
    }
    void helper(TreeNode* root, int r, int c, vector<vector<string>>&ans, int height){
        if(root == NULL) return;
        ans[r][c] = to_string(root->val);
        helper(root->left, r+1, c- pow(2, height-r-1),ans, height);
        helper(root->right, r+1, c+ pow(2, height-r-1),ans, height);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root)-1;
        int m = height+1;
        int n = pow(2, height+1)-1;
        vector<vector<string>>ans(m, vector<string>(n, ""));

        helper(root, 0, (n-1)/2, ans, height);
        return ans;
    }
};