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
    void inorder(TreeNode* root, int k, int &ans){
        int count = 0;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                count++;
                if(count == k){
                    ans = curr->val;
                }
                curr = curr->right;
            } else {
                TreeNode* leftnode = curr->left;

                while(leftnode->right!= NULL && leftnode->right != curr){
                    leftnode = leftnode->right;
                }

                if(leftnode->right == NULL){
                    leftnode->right = curr;
                    curr = curr->left;
                } else {
                    leftnode->right = NULL;
                    count++;
                    if(count ==k){
                        ans = curr->val;
                    }
                    curr= curr->right;
                }
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root,k,ans);
        return ans;
        
    }
};