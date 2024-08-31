/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int r, int c, int n){
        bool found = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[r+i][c+j] != grid[r][c]){
                    found = false;
                    break;
                }
            }
        }
        if(found){
            return new Node(grid[r][c], true);
        }
        n=n/2;
        Node*topleft = helper(grid, r,c,n);
        Node*topright = helper(grid, r,n+c,n);
        Node*bottomleft = helper(grid, n+r,c,n);
        Node*bottomright = helper(grid, n+r,n+c,n);
        return new Node(grid[r][c],false,topleft, topright, bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,0,grid.size());
    }
};