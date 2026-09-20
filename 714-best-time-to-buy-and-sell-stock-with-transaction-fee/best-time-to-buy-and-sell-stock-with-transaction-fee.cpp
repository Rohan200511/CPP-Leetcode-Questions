class Solution {
public:

    int n;

    vector<vector<int>>dp;

    int solve(vector<int>& prices , int i , bool buy , int fee){
        if(i >= n) return 0;

        if(dp[i][buy] != -1e9) return dp[i][buy];

        if(buy){
            return dp[i][buy] = max(
                solve(prices , i + 1 , buy , fee),
                -prices[i] + solve(prices , i + 1 , !buy , fee)
            );
        }

        else{
            return dp[i][buy] = max(
                solve(prices , i + 1 , buy , fee),
                prices[i] - fee + solve(prices , i + 1 , !buy , fee)
            );
        }

    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        dp.assign(n , vector<int>(2 , -1e9));
        return solve(prices , 0 , true , fee);
    }
};