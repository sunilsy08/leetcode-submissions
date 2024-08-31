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
    int helper(TreeNode* root, int & maxsum) {
        if(root == NULL) return 0;

        int l = max(0,helper(root->left, maxsum));
        int r = max(0,helper(root->right, maxsum));        
        int ans = root->val + max(l,r);
// 
        maxsum = max(maxsum, root->val + l + r);
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        if(root == NULL) return 0;
         helper(root, maxsum);
         return maxsum;
    }
};