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
    TreeNode* lca(TreeNode* root,int n1, int n2){
        if(root == NULL) return root;
        
        if(root->val == n1 || root->val == n2){
            return root;
        }
        
        TreeNode * llca = lca(root->left, n1,n2);
        TreeNode * rlca = lca(root->right, n1,n2);
         if (llca && rlca)  return root;
        return llca != NULL ? llca : rlca;
        
    }
    bool  findPath(TreeNode* root, int n, string &ans, string leftword, string rightWord){
        if(root == NULL) return false;
        if(root->val == n)return true;
        
        if(findPath(root->left, n, ans, leftword, rightWord)){
            ans+= leftword;
            return true;
        } 
        else if(findPath(root->right, n, ans, leftword, rightWord)){
            ans+= rightWord;
            return true;
        }
        return false;
    }
    
    string getDirections(TreeNode* root, int st, int dest) {
        TreeNode* lc = lca(root, st, dest );
        string source = "";
        string destination = "";
        if(lc->val == st){
            findPath(lc, dest, source, "L", "R");
            reverse(source.begin(), source.end());
            return source;
        }
        findPath(lc, st, source, "U", "U");
        findPath(lc, dest, destination, "L", "R");
        reverse(destination.begin(), destination.end());
        return source + destination;
    }
};