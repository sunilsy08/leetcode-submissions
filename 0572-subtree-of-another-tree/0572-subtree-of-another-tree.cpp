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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(!root || !subRoot) return false;

        return root->val == subRoot->val && isSame(root->left, subRoot->left) 
        && isSame(root->right, subRoot->right);
    }
    void encodeTree(TreeNode* root, string &s){
        if(root == NULL){
            s += "N";
            return;
        }
        s += "#" + to_string(root->val);
        s +=",";
        encodeTree(root->left, s);
        s +=",";
        encodeTree(root->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(root == NULL && subRoot == NULL) return true;
        // if(root== NULL || subRoot == NULL) return false;
        // if(isSame(root, subRoot)) return true;

        // return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        string s1, s2;
        encodeTree(root, s1);
        encodeTree(subRoot, s2);
        cout<<s1<<"\n";
        cout<<s2<<"\n";
        if(s1.find(s2) < s1.size()) return true;
        return false;
    }
};