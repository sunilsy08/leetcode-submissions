class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, 
    int inicolor, int color) {
        if(sr<0 || sc<0 || sr>= image.size() || sc>= image[0].size()
            || image[sr][sc] != inicolor
        ) return;

       
            image[sr][sc] = color;
            dfs(image, sr-1, sc, inicolor, color);
            dfs(image, sr+1, sc, inicolor, color);
            dfs(image, sr, sc-1, inicolor, color);
            dfs(image, sr, sc+1, inicolor, color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if (iniColor == color) {
            return image;
        }
        dfs(image, sr, sc, iniColor, color);
        return image;
    }
};