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
    bool isEqual(TreeNode*t1, TreeNode*t2){
        if(t1== NULL || t2== NULL) {
            if(t1== NULL && t2== NULL) return true;
            return false;
        }

        if(t1->val == t2->val){
            return isEqual(t1->left, t2->right) 
                && isEqual(t1->right, t2-> left);
        }
        return false;
        
        
    }
    bool isSymmetric(TreeNode* root) {
     
        if(!root) return true;
        return isEqual(root->left, root->right);
    }
};