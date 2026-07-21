class Solution {
  public:
    
    int n;
    
    
    vector<vector<int>>dp;
    
    int solve(int W , vector<int>& val , vector<int>& wt , int n){
        if(n == 0 || W == 0){
            return 0;
        }
        
        if(dp[n][W] != -1) return dp[n][W];
        
        int pick = 0;
        
        if(W >= wt[n - 1]){
            pick = val[n - 1] + solve(W - wt[n - 1] , val , wt , n - 1);
        }
        
        int not_pick = solve(W , val , wt , n - 1);
        
        return dp[n][W] = max(pick , not_pick);
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        dp.assign(n + 1 , vector<int>(W + 1 , -1));
        return solve(W , val , wt , n);
    }
};