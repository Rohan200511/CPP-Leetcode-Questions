class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyp = INT_MAX;
        int profit = 0;
        int n = prices.size();

        for(int i = 0 ;i<n ;i++){
            buyp = min(buyp , prices[i]);
            profit = max(profit , prices[i] - buyp);
        }
        return (profit > 0) ? profit : 0;
    }
};