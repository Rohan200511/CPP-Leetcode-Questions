class Solution {
public:

    void dfs(vector<vector<int>>& image , int n , int m , int sr , int sc , int color , int startingColor){
        if(sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != startingColor || image[sr][sc] == color) return;

        image[sr][sc] = color;

        dfs(image , n , m , sr+1 , sc , color , startingColor);
        dfs(image , n , m , sr-1 , sc , color , startingColor);
        dfs(image , n , m , sr , sc+1 , color , startingColor);
        dfs(image , n , m , sr , sc-1 , color , startingColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startingColor = image[sr][sc];
        dfs(image , n , m , sr , sc , color , startingColor);
        return image;
    }
};