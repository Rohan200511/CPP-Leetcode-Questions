class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        if(n == 1) return s;
        
        int maxL = 1 , idx = 0;

        vector<vector<bool>>dp(n , vector<bool>(n , false));

        for(int i = 0 ; i < n ; i++) dp[i][i] = true;

        for(int len = 2 ; len <= n ; len++){
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1;

                if(i+1 == j && s[i] == s[j]) {
                    dp[i][j] = true;
                    maxL = 2;
                    idx = i;
                }

                else if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    if(maxL < j - i + 1){
                        maxL = j - i + 1;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx , maxL);
    }
};