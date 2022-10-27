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
  void dfs(int r, int c, int n, int m, vector<vector<int>>&grid, vector<vector<bool>>&visited) {
      visited[r][c] = true;
      
      for(int i=0;i<4; i++) {
          int row = r+ delrow[i];
          int col = c + delcol[i];
          
          if(row>=0 && row< n && col >=0 && col < m
            && !visited[row][col] && grid[row][col] == 1
          ) {
              dfs(row, col, n, m, grid, visited);
          }
      }
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        // for first and last row
        for(int i=0;i<m;i++) {
            if (!visited[0][i] && grid[0][i] ==1 ) {
                dfs(0,i,n,m,grid, visited);
            }
            
            if(n!=1 && !visited[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1,i,n,m,grid,visited);
            }
        }
        
        // for first and last column
        for(int i=0;i<n;i++) {
            if (!visited[i][0] && grid[i][0] ==1 ) {
                dfs(i,0,n,m,grid, visited);
            }
            
            if(m!=1 && !visited[i][m-1] && grid[i][m-1] == 1) {
                dfs(i,m-1,n,m,grid,visited);
            }
        }
        int count =0;
        for(int i=0; i<n; i++) {
            for(int j=0;j<m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) 
                count++;
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends