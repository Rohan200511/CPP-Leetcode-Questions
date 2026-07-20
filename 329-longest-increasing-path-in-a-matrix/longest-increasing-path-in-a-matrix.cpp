class Solution {
public:

    int n , m;
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& matrix , int i , int j , int prev){
        if(i >= n || i < 0 || j >= m || j < 0) return 0;

        if(matrix[i][j] <= prev) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(matrix , i + 1 , j , matrix[i][j]);
        int right = solve(matrix , i , j + 1 , matrix[i][j]);
        int up = solve(matrix , i - 1 , j , matrix[i][j]);
        int left = solve(matrix , i , j - 1, matrix[i][j]);

        return dp[i][j] = 1 + max({down , right , up , left});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n , vector<int>(m , -1));

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans , solve(matrix , i , j , INT_MIN));
            }
        }
        return ans;
    }
};