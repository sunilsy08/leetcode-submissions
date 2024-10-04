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
    TreeNode*getinorderSuccessor(TreeNode* root){
        TreeNode* temp = root->right;
        while(temp->left){
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        } else if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else {
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            } else if(root->right == NULL){
                root = root->left;
            } else if(root->left == NULL){
                root = root->right;
            } else {
                TreeNode*succ = getinorderSuccessor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};