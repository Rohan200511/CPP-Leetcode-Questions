class Solution {
public:

    int n , m;
    vector<vector<int>>dp;

    bool solve(const string& s , const string& p , int i , int j){
        if(j == m) return i == n;

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*'){
            return dp[i][j] = ((i < n) && solve(s , p , i + 1 , j)) || solve(s , p , i , j + 1);
        }

        else{
            bool match = (i < n) && (s[i] == p[j] || p[j] == '?');

            return dp[i][j] = match && solve(s , p , i + 1 , j + 1);
        }
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        dp.assign(n + 2 , vector<int>(m + 2 , -1));
        return solve(s , p , 0 , 0);
    }
};