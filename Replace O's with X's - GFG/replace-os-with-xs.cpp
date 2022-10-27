//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        
        bool visited[n][m];
        memset(visited, false, sizeof(visited));
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || i== n-1 || j==0 || j== m-1) {
                    if(mat[i][j] == 'O') {
                        q.push(make_pair(i,j));
                        visited[i][j] = true;
                    }
                }
            }
        }
        int delrow[]= {-1,0,+1,0};
	    int delcol[]= {0,+1,0,-1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                
                if(row>=0 && col>=0 && row<n && col<m && !visited[row][col] && mat[row][col] == 'O') {
                    q.push(make_pair(row,col));
                    visited[row][col] = true;
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends