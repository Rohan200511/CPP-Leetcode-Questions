class Solution {
  public:
    
    int n;
    vector<int>dp;
    int solve(vector<int>& price , int n){
        if(n == 0) return 0;
        if(dp[n] != -1e9) return dp[n];
        int max_val = price[n - 1];
        
        for(int k = 1 ; k <= n ; k++){
            max_val =  max(max_val , price[k - 1] + solve(price , n - k));
        }
        
        return dp[n] = max_val;
    }
    
    int cutRod(vector<int> &price) {
        // code here
        n = price.size();
        dp.assign(n+1 , -1e9);
        return solve(price , n);
    }
};