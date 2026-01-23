class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n , vector<int>(m));

        int max_side = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){ 
                    dp[i][j] = matrix[i][j] - '0';
                    max_side = max(max_side , dp[i][j]);
                }

                else{
                    if(matrix[i][j] == '0') dp[i][j] = 0;

                    else{
                        int top = dp[i-1][j];
                        int left = dp[i][j-1];
                        int diagonal = dp[i-1][j-1];

                        dp[i][j] = 1 + min({top , left , diagonal});
                        max_side = max(max_side , dp[i][j]);
                    }
                }
            }
        }
        return max_side * max_side;
    }
};