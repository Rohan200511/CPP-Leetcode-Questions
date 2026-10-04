class Solution {
public:

    int n;
    vector<vector<int>>dp;

    bool solve(string& s , int i , int balance){
        if(i == n) return balance == 0;

        if(balance < 0) return false;

        if(dp[i][balance] != -1) return dp[i][balance];

        bool ans;

        if(s[i] == '(') ans = solve(s , i + 1 , balance + 1);
        else if(s[i] == ')') ans = solve(s , i + 1 , balance - 1);
        else{
            ans = solve(s , i + 1 , balance + 1) || solve(s , i + 1 , balance - 1) || solve(s , i + 1 , balance);
        }

        return dp[i][balance] = ans;
    }

    bool checkValidString(string s) {
        n = s.length();
        dp.assign(n + 1 , vector<int>(n + 1 , -1));
        return solve(s , 0 , 0);
    }
};