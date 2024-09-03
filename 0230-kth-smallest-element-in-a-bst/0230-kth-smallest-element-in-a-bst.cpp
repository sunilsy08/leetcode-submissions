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
    bool helper(TreeNode* root, int k, int&level, int &ans) {
        if(root == NULL) return false;
        if (helper(root->left, k, level, ans)){
            return true;
        }
        level++;
        if(level ==k) {
            ans = root->val;
            return true;
        }
        return helper(root->right, k, level, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int level = 0;
         helper(root, k, level, ans);
         return ans;
    }
};