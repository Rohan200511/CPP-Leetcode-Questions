class Solution {
public:
    int n , m;
    vector<vector<int>>t;

    int dfs(vector<vector<int>>& grid , int i , int j){
        if(i == n-1 && j == m-1) return grid[i][j];

        if(i >= n || j >= m) return INT_MAX;

        if(t[i][j] != -1) return t[i][j];

        int right = dfs(grid , i , j+1);
        int down = dfs(grid , i+1 , j);

        return t[i][j] =  grid[i][j] + min(down , right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        t.assign(n , vector<int>(m , -1));
        return dfs(grid, 0 , 0);
    }
};