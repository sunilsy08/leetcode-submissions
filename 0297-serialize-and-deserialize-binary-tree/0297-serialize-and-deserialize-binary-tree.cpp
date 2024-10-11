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
    void helper(TreeNode* root, string& serializedTree){
        if(root == NULL){
            serializedTree += "N";
            return;
        }

        serializedTree+= to_string(root->val);
        serializedTree+=',';
        helper(root->left, serializedTree);
        serializedTree+=',';
        helper(root->right, serializedTree);
    }
    string serialize(TreeNode* root) {
        string serializedTree = "";
        helper(root, serializedTree);
        return serializedTree;
    }

    TreeNode* helperD(istringstream& iss){
        string value;
        TreeNode* root = NULL;
        if(!getline(iss, value, ',')){
             return NULL;
        }
        if(value == "N"){
            return NULL;
        }

        root = new TreeNode(stoi(value));
        root->left = helperD(iss) ;
        root->right = helperD(iss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return helperD(iss);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));