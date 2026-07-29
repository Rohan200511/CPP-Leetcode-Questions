class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int buy = -prices[0];
        int profit = 0;

        for(int i = 0 ; i < n ; i++){
            
            int prev_profit = profit;

            profit = max(profit , buy + prices[i] - fee);

            buy = max(buy , prev_profit - prices[i]);
        }
        return profit;
    }
};