class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>>dp(n , vector<bool>(n , false));

        for(int i = 0; i <n; i++) dp[i][i] = true;

        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;

                if(len == 2 && s[i] == s[j]) dp[i][j] = true;

                else if(s[i]==s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                }
            }
        }

        int ind = 0;
        int len = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < n ; j++){
                if(dp[i][j] && j - i + 1 > len){
                    ind = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(ind , len);
    }
};