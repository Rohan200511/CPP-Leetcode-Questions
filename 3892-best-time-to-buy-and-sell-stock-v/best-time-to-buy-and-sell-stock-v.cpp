class Solution {
public:

    int n;

    vector<vector<vector<long long>>>dp;

    long long solve(vector<int>& prices , int k , int i , int txn){
        if(i >= n || k == 0){
            if(txn != 0) return -1e15;
            return 0;
        }

        if(dp[i][k][txn] != -1e15) return dp[i][k][txn];

        if(txn == 0){ // kuch ni h mere pass

            return dp[i][k][txn] = max({
                solve(prices , k , i + 1 , txn),
                -prices[i] + solve(prices , k , i + 1 , 1),
                prices[i] + solve(prices , k , i + 1 , 2)
            });

        }

        else if(txn == 1){ // holding a stock
            return dp[i][k][txn] = max(
                solve(prices , k , i + 1 , txn),
                (long long)prices[i] + solve(prices , k - 1 , i + 1 , 0)
            );
        }

        else{ // short txn
            return dp[i][k][txn] = max(
                solve(prices , k , i + 1 , txn),
                (long long)-prices[i] + solve(prices , k - 1 , i + 1 , 0)
            );
        }
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.assign(n , vector<vector<long long>>(k + 1 , vector<long long>(4 , -1e15)));
        return solve(prices , k , 0 , 0);
    }
};