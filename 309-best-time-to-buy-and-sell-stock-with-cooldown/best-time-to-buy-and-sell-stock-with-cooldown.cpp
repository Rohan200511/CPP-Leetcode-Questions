class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solve(vector<int>& prices , int i , bool buy){
        if(i >= n) return 0;

        if(dp[i][buy] != -1e9) return dp[i][buy];

        if(buy){
            return dp[i][buy] = max(
                solve(prices , i + 1 , buy),
                -prices[i] + solve(prices , i + 1 , !buy)
            );
        }
        else{
            return dp[i][buy] = max(
                solve(prices , i + 1 , buy),
                prices[i] + solve(prices , i + 2 , !buy)
            );
        }

    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n , vector<int>(2 , -1e9));
        return solve(prices , 0 , true);
    }
};