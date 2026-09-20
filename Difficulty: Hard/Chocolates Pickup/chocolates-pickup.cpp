class Solution {
  public:
    
    int n , m;
    vector<vector<vector<int>>>dp;
    
    int solve(vector<vector<int>>& grid , int i , int j1 , int j2){
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
                return -1e9; 
            }
        
        if(i == n - 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1e9) return dp[i][j1][j2];
        
        int maxiAns = -1e9; 
        
        for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
            for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                int ans = 0;
                if(j1 == j2){
                    ans = grid[i][j1];
                }
                else ans = grid[i][j1] + grid[i][j2];
                
                ans += solve(grid , i + 1 , j1 + dj1 , j2 + dj2);
                
                maxiAns = max(ans , maxiAns);
            }
        }
        return dp[i][j1][j2] = maxiAns;
        
    }
    
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();
        dp.assign(n , vector<vector<int>>(m , vector<int>(m , -1e9)));
        return solve(grid , 0 , 0 , m - 1);
    }
};