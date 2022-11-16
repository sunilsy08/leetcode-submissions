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
    bool helper(TreeNode*root, TreeNode*maxNode, TreeNode*minNode) {
        if(root == NULL) return true;
        if(maxNode != NULL && root->val >= maxNode->val ) return false;
        if(minNode != NULL && root->val <= minNode->val) return false;
        
        return helper(root->left, root, minNode) && helper(root->right, maxNode, root);

    }
    bool isValidBST(TreeNode* root) {
        
        return helper(root,NULL, NULL);
    }
};