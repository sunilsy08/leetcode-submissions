/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node*helper(Node*node, unordered_map<Node*,Node*>&clonedNodes){
       if(node == NULL) return NULL;

       if(clonedNodes.find(node) != clonedNodes.end()){
        return clonedNodes[node];
       }
       
       Node * newNode = new Node(node->val);
       clonedNodes[node] = newNode;

       for(auto it : node->neighbors){
            Node *neighborNode = helper(it, clonedNodes);
            if(neighborNode){
                newNode->neighbors.push_back(neighborNode);
            }
       }
       return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*,Node*>clonedNodes;
        return helper(node, clonedNodes);
    }
};