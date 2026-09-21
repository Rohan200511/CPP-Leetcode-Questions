class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<string> ans;
    
    unordered_set<string>visited[55][55];
    
    void solve(string &s1, string &s2, int i, int j,
               string &curr, int len) {

        if (curr.length() == len) {
            string temp = curr;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        if (i == 0 || j == 0)
            return;
        
        if(visited[i][j].count(curr)) return;
        
        visited[i][j].insert(curr);
        
        if (s1[i - 1] == s2[j - 1]) {

            curr.push_back(s1[i - 1]);

            solve(s1, s2, i - 1, j - 1, curr, len);

            curr.pop_back();
        }
        else {

            if (dp[i - 1][j] >= dp[i][j - 1])
                solve(s1, s2, i - 1, j, curr, len);

            if (dp[i][j - 1] >= dp[i - 1][j])
                solve(s1, s2, i, j - 1, curr, len);
        }
    }

    vector<string> allLCS(string &s1, string &s2) {

        n = s1.size();
        m = s2.size();

        dp.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        ans.clear();

        string curr = "";

        solve(s1, s2, n, m, curr, dp[n][m]);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};