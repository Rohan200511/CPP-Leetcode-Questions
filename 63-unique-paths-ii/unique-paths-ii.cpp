class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 || n == 0 || m == 0) return 0;

        vector<vector<int>>t(n , vector<int>(m));

        t[0][0] = 1;

        for(int i = 1 ; i < m ; i++){
            if(obstacleGrid[0][i] == 0 && t[0][i-1] != 0) t[0][i] = 1;
            else t[0][i] = 0;
        }
        for(int i = 1 ; i < n ; i++){
           if(obstacleGrid[i][0] == 0 && t[i-1][0] != 0) t[i][0] = 1;
           else t[i][0] = 0;
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(obstacleGrid[i][j] == 0) t[i][j] = t[i-1][j] + t[i][j-1];
                else t[i][j] = 0;
            }
        }
        return t[n-1][m-1];
    }
};