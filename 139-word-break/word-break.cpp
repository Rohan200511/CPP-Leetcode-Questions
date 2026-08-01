class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string>st(wordDict.begin() , wordDict.end());

        vector<bool>dp(n + 1 , false);
        dp[0] = true;

        for(int i = 0 ; i < n ; i++){
            if(!dp[i]) continue;

            for(int len = 1 ; i + len <= n ; len++){
                string temp = s.substr(i , len);

                if(st.count(temp)){
                    dp[i + len] = true;
                }
            }
        }
        return dp[n];
    }
};