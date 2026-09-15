class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> dp(
            n + 1, vector<bool>(n + 1, false)
        );

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (len == 1) {
                    dp[i][j] = true;
                }
                else if (len == 2 && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else if (len >= 3) {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        vector<int> arr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1];

            for (int j = 0; j < i; j++) {
                int len = i - j;

                if (len >= k && dp[j][i - 1]) {
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
        }

        return arr[n];
    }
};