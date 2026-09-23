class Solution {
  public:
        
    vector<vector<int>>dp;
        
    int solve(vector<int>& arr , int i , int j){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        
        for(int k = i ; k < j ; k++){
            int cost = solve(arr , i , k) + solve(arr, k + 1 , j) + arr[i-1] * arr[k] * arr[j];
            ans = min(ans , cost);
        }
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        dp.assign(n + 1 , vector<int>(n + 1 , -1));
        return solve(arr , 1 , n - 1);
    }
};