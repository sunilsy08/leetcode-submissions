//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n = grid.size();
        if(n<1) return -1;
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        int max_time = 0;
        while(!q.empty()) {
            pair<pair<int,int>,int> curr = q.front();
            q.pop();
            int r = curr.first.first;
            int c = curr.first.second;
            int time = curr.second;
            max_time = max(max_time,time);
            int row,col;
            for(int i=0;i<4;i++) {
                row = r+delrow[i];
                col = c+delcol[i];
                if( row>=0
                && row <n
                && col >=0
                && col <m
                && grid[row][col] == 1
                ) {
                    grid[row][col] = 2;
                    q.push(make_pair(make_pair(row,col), time+1));
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return max_time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends