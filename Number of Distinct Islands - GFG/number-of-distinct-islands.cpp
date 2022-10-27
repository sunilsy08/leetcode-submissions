//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    int delrow[4]= {-1,0,+1,0};
	int delcol[4]= {0,+1,0,-1};
  void dfs(int r, int c, int pr, int pc,vector<vector<int>>& grid, vector<vector<bool>>&visited, vector<pair<int,int>>&v ) {
      visited[r][c] = true;
      v.push_back(make_pair(r-pr, c-pc));
      for(int i=0; i<4; i++) {
          int row = r + delrow[i];
          int col = c + delcol[i];
          
          if(row >= 0 && row < grid.size() && col>=0 && col < grid[0].size()
            && !visited[row][col] && grid[row][col] == 1
          ) {
              dfs(row,col,pr, pc, grid, visited, v);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        set<vector<pair<int,int>>>shapes;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>>v;
                    dfs(i,j,i,j,grid, visited,v);
                    shapes.insert(v);
                }
            }
        }
        return shapes.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends