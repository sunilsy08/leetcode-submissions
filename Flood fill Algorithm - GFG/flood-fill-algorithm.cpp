//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> help(vector<vector<int>>& image, int sr, int sc, int newColor, int start_color = -1) {
        // Code here 
        // if(!isValid(sr,sc,image)) return image;
        if (sr<0 || sc <0 || sr >= image.size() || sc>= image[0].size() || 
        image[sr][sc] == newColor || (image[sr][sc]!= start_color)) 
        return image;
        int x = image[sr][sc];
        image[sr][sc] = newColor;
        
        help(image,sr-1,sc,newColor, x);
        help(image,sr+1,sc,newColor,x);
        help(image,sr,sc-1,newColor,x);
        help(image,sr,sc+1,newColor,x);

        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int start_color = -1) {
        // Code here 
        // if(!isValid(sr,sc,image)) return image;
        // if (sr<0 || sc <0 || sr >= image.size() || sc>= image[0].size() || 
        // image[sr][sc] == 0 || image[sr][sc] == newColor || (start_color!= -1 && image[sr][sc]!= start_color)) 
        // return image;
        int x = image[sr][sc];
        return help(image,sr,sc,newColor,x);
        // image[sr][sc] = newColor;
        
        // floodFill(image,sr-1,sc,newColor, x);
        // floodFill(image,sr+1,sc,newColor,x);
        // floodFill(image,sr,sc-1,newColor,x);
        // floodFill(image,sr,sc+1,newColor,x);

        // return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends