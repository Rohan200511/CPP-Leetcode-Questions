class Solution {
public:

    int n , m;

    vector<vector<int>>dp;

    int solve(vector<vector<int>>& grid , int i , int j){
        if(i >= n || j >= m || grid[i][j] == 1) return 0;
        if(i == n - 1 && j == m - 1) return 1;
    
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(grid , i , j + 1);
        int down = solve(grid , i + 1 , j);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        dp.assign(n , vector<int>(m , -1));

        return solve(obstacleGrid , 0 , 0);
    }
};