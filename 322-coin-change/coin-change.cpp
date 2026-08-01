class Solution {
public:

    int n;
    const int INF = 1e9;
    vector<vector<int>>dp;

    int solve(vector<int>& coins , int amount , int i){
        if(amount == 0) return 0;

        if(amount < 0) return INF;
        if(i == n) return INF;

        if(dp[amount][i] != -1) return dp[amount][i];

        int take = INF;

        if(amount >= coins[i]){
            take = 1 + solve(coins , amount - coins[i] , i);
           
        }

        int skip = solve(coins , amount , i + 1);

        return dp[amount][i] = min(take , skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        
        dp.assign(amount + 1 , vector<int>(n + 1 , -1));

        int ans = solve(coins , amount , 0);

        return (ans == INF) ? -1 : ans;
    }
};