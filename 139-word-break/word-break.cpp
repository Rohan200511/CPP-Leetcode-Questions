class Solution {
public:

    int n;
    unordered_set<string>st;
    vector<int>dp;

    bool solve(string& s , int i){
        
        if(i >= n) return true;

        if(dp[i] != -1) return dp[i];

        for(int j = i ; j < n ; j++){
            string temp = s.substr(i , j - i + 1);

            if(st.count(temp) && solve(s , j + 1)){
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(string& word : wordDict){
            st.insert(word);
        }
        
        dp.assign(n , -1);

        return solve(s , 0);
    }
};