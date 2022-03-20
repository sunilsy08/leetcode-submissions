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
    int height(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int positionFromLeaf(TreeNode* root, vector<vector<int>>&ans){
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) return 0;
        int lpos = 0, rpos=0;
        if(root->left){
            lpos = positionFromLeaf(root->left, ans);
            ans[lpos].push_back(root->left->val);
        }
        if(root->right){
            rpos = positionFromLeaf(root->right, ans);
            ans[rpos].push_back(root->right->val);
        }
        

        return max(lpos, rpos) + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        int h = height(root);
        vector<vector<int>>ans(h);
        if(!root) return ans;
        
        positionFromLeaf(root, ans);
        ans[h-1].push_back(root->val);
        return ans;
        
    }
};