class Solution {
public:

    int n , m;
    vector<vector<unsigned long long>>dp;

    /*int solve(string& s , string& t , int i , int j){
        if(j >= m) return 1;
        if(i >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] =  solve(s , t , i + 1 , j + 1) + solve(s , t , i + 1 , j);
        else return dp[i][j] = solve(s , t , i + 1 , j);
    }
*/
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        // dp.assign(n , vector<int>(m , -1));
        //return solve(s , t , 0 , 0);

        dp.assign(n + 1 , vector<unsigned long long>(m + 1 , 0));

        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }
                else dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};