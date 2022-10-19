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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(l>0 && r>0) return min(l,r) + 1;
        if(l>0) return l+1;
        return r+1;
    }
};