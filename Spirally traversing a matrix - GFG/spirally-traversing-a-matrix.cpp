//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int delrow[4] = {0,+1,0,-1};
        int delcol[4] = {1,0,-1,0};
        vector<vector<bool> > seen(r, vector<bool>(c, false));

        int row=0,col=0,dir=0;
        vector<int>ans;
        
        for(int i=0; i< (r*c) ;i++) {
            ans.push_back(matrix[row][col]);
            seen[row][col] = true;
            int newrow = row+delrow[dir];
            int newcol = col + delcol[dir];
            if(newrow>=0 && newcol >= 0 && newrow<r && newcol< c && !seen[newrow][newcol]) {
                row = newrow;
                col = newcol;
            } else{
                dir = (dir+1)%4;
                row = row+delrow[dir];
                col = col + delcol[dir];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends