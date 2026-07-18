class Solution {
public:

    int n;
    vector<int>dp;

    int solve(string& s , int i){
        if(i == n) return 1;
        if(s[i] == '0') return dp[i] = 0;

        if(dp[i] != -1) return dp[i];

        int ans = solve(s , i + 1);

        if(i + 1 < n){
            if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'){
                ans += solve(s , i + 2);
            }
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        n = s.length();
        
        dp.assign(n , -1);
        return solve(s , 0);
    }
};