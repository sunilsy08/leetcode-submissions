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
    string lw;
    string rw;
    TreeNode* lca(TreeNode* root,int n1, int n2, bool &v1, bool &v2){
        if(root == NULL) return root;
        
        if(root->val == n1){
            v1 = true;
            return root;
        }
        if(root-> val == n2) {
            v2 = true;
            return root;
        }
        
        TreeNode * llca = lca(root->left, n1, n2, v1, v2);
        TreeNode * rlca = lca(root->right, n1, n2, v1, v2);
         if (llca && rlca)  return root;
        return llca != NULL ? llca : rlca;
        
    }
    bool  findPath(TreeNode* root, int n, string &ans){
        int now = root == NULL ? -1 : root->val;
        if(root == NULL) return false;
        if(root->val == n){
            return true;
        }
        if(findPath(root->left, n, ans)){
            ans+= this->lw;
            return true;
        } else if(findPath(root->right, n, ans)){
            ans+= this->rw;
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int st, int dest) {
        bool v1 = true, v2 = true;
        TreeNode* lc = lca(root, st, dest, v1, v2 );
        string source = "";
        string destination = "";
        if(lc->val == st){
            this->lw="L";
            this->rw="R";
            findPath(lc, dest, source);
            reverse(source.begin(), source.end());
            return source;
        }
        this->lw="U";
        this->rw="U";
        findPath(lc, st, source);
        this->lw="L";
        this->rw="R";
        findPath(lc, dest, destination);
        reverse(destination.begin(), destination.end());
        return source + destination;
    }
};