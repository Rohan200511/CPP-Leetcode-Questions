class Solution {
public:

    int n , m;
    vector<vector<int>>dp;

    bool solve(const string& s , const string& p , int i , int j){
        if(j == m){
            return i == n;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if(p[j] == '*'){
            ans = ((i < n) && solve(s , p , i + 1 , j)) || solve(s , p , i , j + 1);
        }
        else{
            bool firstMatch = (i < n) && (s[i] == p[j] || p[j] == '?');

            ans = firstMatch && solve(s , p , i + 1 , j + 1);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();

        dp.assign(n + 1 , vector<int>(m + 1 , -1));

        return solve(s , p , 0 , 0);
    }
};