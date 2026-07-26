class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool>>dp(n , vector<bool>(n , false));

        for(int i = 0 ; i < n ; i++) dp[i][i] = true;

        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len <= n ; i++){
                int j = i + len - 1;

                if(len == 2 && s[i] == s[j]) dp[i][j] = true;

                else if(s[i] == s[j] && dp[i + 1][j - 1] == true){
                    dp[i][j] = true;
                }
            }
        }

        vector<int>ans(n , INT_MAX);

        for(int i = 0 ; i < n ; i++){
            if(dp[0][i] == true) ans[i] = 0;

            else{
                for(int k = 0 ; k < i ; k++){
                    if((dp[k + 1][i] == true) && 1 + ans[k] < ans[i]){
                        ans[i] = 1 + ans[k];
                    }
                }
            }
        }
        return ans[n - 1];
    }
};