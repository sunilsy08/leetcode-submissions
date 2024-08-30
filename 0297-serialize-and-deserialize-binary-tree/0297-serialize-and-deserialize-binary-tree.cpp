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
        if(root == NULL){
            return "N";
        }
        string curr = to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);
        return curr+','+l+','+r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Create a stream from the data string
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        // Read until the next comma
        if (!getline(iss, val, ',')) return NULL; 

        if (val == "N") {
            return NULL; // Null indicator
        }
        // Create node with the current value
        TreeNode* node = new TreeNode(stoi(val)); 
        // Recursively build left subtree
        node->left = deserializeHelper(iss); 
        // Recursively build right subtree
        node->right = deserializeHelper(iss); 
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));