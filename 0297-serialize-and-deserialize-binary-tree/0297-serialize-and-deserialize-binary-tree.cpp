/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        string ans = "";
        helper(root,ans);
        cout<<"Serialized: "<< ans;
        return ans;
    }
    void helper(TreeNode*root, string&ans){
        if(root == NULL){
            ans += "N";
            return;
        }
        ans += to_string(root->val);
        // if(root->left){
            ans +=",";
            helper(root->left, ans);
        // }
        // if(root->right)
        ans += ",";
        helper(root->right,ans);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        ios_base::sync_with_stdio(false);
        istringstream iss(data);
        return helperD(iss);
    }

    TreeNode*helperD(istringstream& iss){
        string val;
        if(!getline(iss,val,',')) return NULL;
        if(val == "N") return NULL;

        TreeNode*node = new TreeNode(stoi(val));
        node->left = helperD(iss);
        node->right = helperD(iss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));