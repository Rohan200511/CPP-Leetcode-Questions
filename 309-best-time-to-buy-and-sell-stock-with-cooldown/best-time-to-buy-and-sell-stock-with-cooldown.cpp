class Solution {
public:

    int n;

    vector<vector<int>>dp;

    int solve(vector<int>& prices , int i , bool buy){
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){
            int take = -prices[i] + solve(prices , i + 1 , !buy);
            int notTake = solve(prices , i + 1 , buy);
            profit = max({profit , take , notTake});
        }

        else{
            int sell = prices[i] + solve(prices , i + 2 , !buy);
            int not_sell = solve(prices , i + 1 , buy);
            profit = max({sell , not_sell , profit});
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n , vector<int>(2 , -1));
        return solve(prices , 0 , true);
    }
};