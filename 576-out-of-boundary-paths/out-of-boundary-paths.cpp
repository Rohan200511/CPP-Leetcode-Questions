class Solution {
public: 

    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>>dp;

    long long dfs(int m , int n , int maxMove , int row , int col){

        if(row < 0 || row >= m || col < 0 || col >= n) return 1;

        if(maxMove == 0) return 0;

        if(dp[row][col][maxMove] != -1) return dp[row][col][maxMove];

        long long ways = 0;

        ways += dfs(m , n , maxMove - 1 , row + 1 , col);
        ways += dfs(m , n , maxMove - 1 , row - 1 , col);
        ways += dfs(m , n , maxMove - 1 , row , col + 1);
        ways += dfs(m , n , maxMove - 1 , row , col - 1);

        return dp[row][col][maxMove] = ways % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        dp.assign( m + 1 , vector<vector<int>>(n + 1 , vector<int>(maxMove +1 , -1)));
        return dfs(m , n , maxMove , startRow , startColumn);
    }
};