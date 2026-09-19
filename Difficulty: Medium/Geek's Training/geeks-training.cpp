class Solution {
  public:
        
    int n;
    
    vector<vector<int>>dp;
    
    int solve(vector<vector<int>>& mat , int i , int prev){
        if(i >= n) return 0;
        
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        
        int ans = INT_MIN;
        
        
        for(int j = 0 ; j < 3 ; j++){
            if(j != prev)
                ans = max({ans , mat[i][j] + solve(mat , i + 1 , j)});
        }
        if(prev != -1) dp[i][prev] = ans;
        return ans;
    }
    
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        n = mat.size();
        dp.assign(n , vector<int>(3 , -1));
        return solve(mat , 0 , -1);
    }
};