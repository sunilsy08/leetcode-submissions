//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int i, int j, int n, int m,vector<vector<char>>& grid, vector<vector<bool>>&visited) {
        return i<n 
        && j<m 
        && i>=0 
        && j>=0 
        && grid[i][j] =='1' 
        && !visited[i][j];
    }
    
    void dfs(int i, int j, int n, int m,vector<vector<char>>& grid, vector<vector<bool>>&visited) {
        if(!isValid(i,j,n,m,grid, visited)) {
            return;
        }
        visited[i][j] = true;
        dfs(i-1,j-1,n,m,grid,visited);
        dfs(i-1,j,n,m,grid,visited);
        dfs(i-1,j+1,n,m,grid,visited);
        dfs(i,j+1,n,m,grid,visited);
        dfs(i+1,j+1,n,m,grid,visited);
        dfs(i+1,j,n,m,grid,visited);
        dfs(i+1,j-1,n,m,grid,visited);
        dfs(i,j-1,n,m,grid,visited);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n<1) return 0;
        int m = grid[0].size();
        int count =0;

        vector<vector<bool>> visited( n , vector<bool> (m, false)); 
        // memset(visited, false, sizeof(visited));
        
        for(int i=0;i<n;i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    count ++;
                    dfs(i,j,n,m,grid,visited);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends