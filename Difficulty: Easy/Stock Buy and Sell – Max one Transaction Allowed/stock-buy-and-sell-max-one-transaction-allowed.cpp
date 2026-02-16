class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int buyP = prices[0];
        int ans = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            
            buyP = min(buyP , prices[i]);
            ans = max(ans , prices[i] - buyP);
        }
        return ans;
    }
};
