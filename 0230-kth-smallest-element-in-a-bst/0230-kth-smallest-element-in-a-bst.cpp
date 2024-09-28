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
    int helper(TreeNode* root, int k, int &count){
                if(root == NULL) return -1;
        if(count == k) return root->val;
        int l = helper(root->left, k, count);

        if(l!= -1){
            return l;
        }
        count++;
        if(count == k) return root->val;
        return helper(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        return helper(root, k, count);
    }
};