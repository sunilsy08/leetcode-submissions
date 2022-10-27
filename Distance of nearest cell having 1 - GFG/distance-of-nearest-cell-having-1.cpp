//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<m;j++) {
	            if(grid[i][j] == 1) {
	                q.push(make_pair(make_pair(i,j),0));
	                ans[i][j]=0;
	            }
	        }
	    }
	    int delrow[]= {-1,0,+1,0};
	    int delcol[]= {0,+1,0,-1};
	    while(!q.empty()) {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        q.pop();
	        ans[r][c] = min(ans[r][c], d);
	        for(int i=0;i<4;i++) {
	            int row = r+delrow[i];
	            int col = c+delcol[i];
	            if(row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0 && ans[row][col] == INT_MAX) {
	                q.push(make_pair(make_pair(row,col), d+1));
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends