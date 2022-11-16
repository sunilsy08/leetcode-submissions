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
    bool helper(TreeNode*root, long max, long min) {
        if(root == NULL) return true;
        // if(!((root->val == INT_MAX && max == INT_MAX ) || (root->val == INT_MIN && min == INT_MIN))){
            if(  (root->val<= min || root->val >= max) ) return false;
            
        // }
        
        if(!root->right && !root->left) return true;
        
        if(root->left && root->left->val > root->val) return false;
        if(root->right && root->right->val < root->val) return false;
        
        return helper(root->left, root->val, min) && helper(root->right, max, root->val);

    }
    bool isValidBST(TreeNode* root) {
        long max = long(INT_MAX) + 1;
        long min = long(INT_MIN) - 1;
        
        return helper(root,max, min);
    }
};