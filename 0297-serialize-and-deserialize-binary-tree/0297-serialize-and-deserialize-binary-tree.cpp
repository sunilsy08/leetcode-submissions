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
    void serializeHelper(TreeNode*root, string & serializedTree){
        if(root == NULL){
            serializedTree += "N";
            return;
        }

        serializedTree += to_string(root->val);
        serializedTree += ',';
        serializeHelper(root->left, serializedTree);
        serializedTree += ',';
        serializeHelper(root->right, serializedTree);
    }
    string serialize(TreeNode* root) {
        string serializedTree = "";
        serializeHelper(root, serializedTree);
        return serializedTree;
    }
    TreeNode* deserializeHelper(istringstream & iss){
        string val;
        if(!getline(iss, val, ',') || val == "N"){
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));