/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        if(root->val < min(p->val, q->val)){
            return lowestCommonAncestor(root->right,p,q);
        } else if(root->val > max(p->val, q->val)) {
            return lowestCommonAncestor(root->left,p,q);
        } 
        return root;

        // TreeNode*l = lowestCommonAncestor(root->left,p,q);
        // TreeNode*r = lowestCommonAncestor(root->right,p,q);
        // if(l&&r) return root;
        // if(l) return l;
        // return r;
    }
};