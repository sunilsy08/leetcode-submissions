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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        TreeNode* curr = root;
        int ans = -1;
        while(curr){
            if(!curr->left){
                count++;
                if(count == k){
                    ans = curr->val;
                }
                curr = curr->right;
            } else {
                TreeNode* currleft = curr->left;
                while(currleft->right && currleft->right !=curr){
                    currleft = currleft->right;
                }
                if(currleft->right == NULL){
                    currleft->right = curr;
                    curr = curr->left;
                } else {
                    currleft->right = NULL;
                    count++;
                    if(count ==k){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;  
    }
};