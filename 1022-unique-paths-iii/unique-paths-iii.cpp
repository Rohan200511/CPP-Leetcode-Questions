class Solution {
public:

    int paths(vector<vector<int>>& grid,int r,int c,int steps,int sr,int sc,int &ans){
        if(sr<0 || sr>=r || sc<0 || sc>=c || grid[sr][sc] == -1) return ans;

        if(grid[sr][sc] == 2){
            if(steps == 0) ans++;
            return ans;
        }
        int temp = grid[sr][sc];
        grid[sr][sc] = -1;
        paths(grid,r,c,steps-1,sr,sc+1,ans);
        paths(grid,r,c,steps-1,sr,sc-1,ans);
        paths(grid,r,c,steps-1,sr+1,sc,ans);
        paths(grid,r,c,steps-1,sr-1,sc,ans);
        grid[sr][sc] = temp;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); 
        int noofzeros = 0;
        int sr,sc;
        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0) noofzeros++;
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }
            }
        }

        paths(grid,rows,cols,noofzeros+1,sr,sc,ans);

        return ans;
    }
};