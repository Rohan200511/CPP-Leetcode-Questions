class Solution {
public:
    int n , m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& matrix , int i , int j){
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if (matrix[i][j] == 0) return dp[i][j] = 0;

        int right = solve(matrix , i , j + 1);
        int down = solve(matrix , i + 1 , j);
        int diagonal = solve(matrix , i + 1 , j + 1);

        return dp[i][j] = 1 + min({right , down , diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int ans = 0;
        dp.assign(n , vector<int>(m , -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1){
                    ans += solve(matrix , i , j);
                }
            }
        }
        return ans;
    }
};