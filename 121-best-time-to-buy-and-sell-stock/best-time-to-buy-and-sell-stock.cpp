class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyP = INT_MAX;
        int profit = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            profit = max(profit , prices[i] - buyP);
            buyP = min(buyP , prices[i]);
        }
        return profit < 0 ? 0 : profit;
    }
};