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
    TreeNode*getNodeForElement(int ele, unordered_map<int, TreeNode*>&node){
        if(node.find(ele) == node.end()){
            TreeNode*newNode = new TreeNode(ele);
            node[ele] = newNode;
            return newNode;
        }
        return node[ele];
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>node;
        TreeNode*rootNode;
        unordered_set<int> children;

        for(auto description: descriptions){
            int parent = description[0];
            int child = description[1];
            children.insert(child);
            TreeNode*parentNode = getNodeForElement(parent, node);
            TreeNode*childNode = getNodeForElement(child, node);
            if(description[2] == 1 ){
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
        }
        for (auto& description : descriptions) {
            int parent = description[0];
            if (children.find(parent) == children.end()) {
                return  node[parent];
            }
        }
        return NULL;
    }
};