class Solution {
  public:
        
    int n , m;
    
    vector<vector<int>>dp;
    
    int solve(string& s1 , string& s2 , int i , int j){
        if(i >= n || j >= m || s1[i] != s2[j]) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = 1 + solve(s1 , s2 , i + 1 , j + 1);
    }
    
    int longCommSubstr(string& s1, string& s2) {
        // code here
        n = s1.length();
        m = s2.length();
        
        dp.assign(n , vector<int>(m , -1));
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans , solve(s1 , s2 , i , j));
            }
        }
        return ans;
    }
};