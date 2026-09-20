class Solution {
public:

    int n;

    vector<vector<vector<int>>>dp;

    int solve(vector<int>& prices , int i , bool buy , int k){
        if(i >= n || k == 0) return 0;
        if(dp[i][buy][k] != -1e9) return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k] = max(
                solve(prices , i + 1 , buy , k) , 
                -prices[i] + solve(prices , i + 1 , !buy , k)
            );
        }
        else{
            return dp[i][buy][k] = max(
                solve(prices , i + 1 , buy , k),
                prices[i] + solve(prices , i + 1 , !buy , k - 1)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n + 1 , vector<vector<int>>(3 , vector<int>(3 ,  -1e9)));
        return solve(prices , 0 , true , 2); 
    }
};