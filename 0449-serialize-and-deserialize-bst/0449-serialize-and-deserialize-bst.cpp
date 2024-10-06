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


    void helperS(TreeNode*root, string &ser){
        if(root == NULL){
            ser += "N";
            return;
        }
        ser += to_string(root->val);
        ser +=",";
        helperS(root->left, ser);
        ser += ",";
        helperS(root->right, ser);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        helperS(root, ser);
        cout<<ser;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return helperD(iss);
    }

    TreeNode*helperD(istringstream&iss){
        string data;
        if(!getline(iss,data, ',')) return NULL;
        if(data == "N") return NULL;
        TreeNode* root = new TreeNode(stoi(data));
        root->left = helperD(iss);
        root->right = helperD(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;