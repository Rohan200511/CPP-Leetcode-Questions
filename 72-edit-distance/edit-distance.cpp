class Solution {
public:

    int n , m;

    vector<vector<int>>dp;

    int solve(string& s , string& t , int i , int j){
        if(i == n) return m - j;
        if(j == m) return n - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = solve(s , t , i + 1 , j + 1);

        int insert = 1 + solve(s , t , i + 1 , j);
        int deletee = 1 + solve(s , t , i , j + 1);
        int replace = 1 + solve(s , t , i + 1 , j + 1);

        return dp[i][j] = min({insert , deletee , replace});
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        dp.assign(n , vector<int>(m , -1));

        return solve(word1 , word2 , 0 , 0);
    }
};