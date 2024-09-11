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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*curr = root;
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* lefttree = curr->left;
                while(lefttree->right && lefttree->right!=curr){
                    lefttree = lefttree->right;
                }

                if(lefttree->right == NULL){
                    lefttree->right = curr;
                    curr = curr->left;
                } else {
                    lefttree->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};