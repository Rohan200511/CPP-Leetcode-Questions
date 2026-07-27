class Solution {
public:

    int n;

    unordered_set<string>st;

    vector<int>dp;

    bool solve(int i , string& s){
        
        if(i >= n){
            return true;
        }

        if(dp[i] != -1) return dp[i];

        for(int l = 1 ; l <= n ; l++){
            string temp = s.substr(i , l);

            if(st.find(temp) != st.end() && solve(i + l , s)) return dp[i] = true;
        }

        return dp[i] = false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        dp.assign(n , -1);

        for(string word : wordDict){
            st.insert(word);
        }

        return solve(0 , s);
    }
};