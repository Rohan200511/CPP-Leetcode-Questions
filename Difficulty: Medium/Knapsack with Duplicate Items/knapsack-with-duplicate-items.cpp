class Solution {
  public:
    
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>& val, vector<int>& wt, int capacity , int i){
        if(i >= n) return 0;
        if(dp[i][capacity] != -1) return dp[i][capacity];
        int skip = solve(val , wt , capacity , i + 1);
        
        int take = 0;
        
        if(wt[i] <= capacity){
            take = val[i] + solve(val , wt , capacity - wt[i] , i);
        }
        return dp[i][capacity] = max(take , skip);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        n = val.size();
        dp.assign(n+1 , vector<int>(capacity + 1 , -1));
        return solve(val , wt , capacity , 0);
    }
};