class Solution {
public: 

    int n , m;

    vector<vector<int>>dp;

    bool solve(const string& s , const string& p , int i , int j){
        if(j == m) return i == n;

        if(dp[i][j] != -1) return dp[i][j];

        bool match = (i < n) && ((s[i] == p[j]) || p[j] == '.');

        if(j + 1 < m && p[j + 1 ] == '*'){
            bool take = match && solve(s , p , i + 1 , j);

            bool skip = solve(s , p , i , j + 2);

            return dp[i][j] = skip || take;
        }
        return dp[i][j] = match && solve(s , p , i + 1 , j + 1);
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        dp.assign(n + 1 , vector<int>(m + 1 , -1));
        return solve(s , p , 0 , 0);
    }
};