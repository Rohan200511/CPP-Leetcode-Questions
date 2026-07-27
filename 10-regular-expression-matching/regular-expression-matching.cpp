class Solution {
public:

    int n , m;

    vector<vector<int>>dp;

    bool solve(string& s , string& p , int i , int j){
        if (j == m)
            return i == n;

        if(dp[i][j] != -1) return dp[i][j];

        bool firstMatch = (i < n) && ((s[i] == p[j]) || p[j] == '.');

        if(j + 1 < m && p[j + 1] == '*'){
            bool skip = solve(s , p , i , j + 2);
            bool consume = firstMatch && solve(s , p , i + 1 , j);

            return dp[i][j] = skip || consume;
        } 

        return dp[i][j] = firstMatch && solve(s , p , i + 1 , j + 1);
    }    

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();

        dp.assign(n + 1 , vector<int>(m + 1 , -1));

        return solve(s , p , 0 , 0);
    }
};
