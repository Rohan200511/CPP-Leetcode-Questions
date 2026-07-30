class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int>dp(n , 0);

        for(int i = 0 ; i < n ; i++){
            int curr_max = -1;

            for(int j = i ; j < n && j - i + 1 <= k ; j++){
                curr_max = max(curr_max , arr[j]);
                int prev = (i == 0) ? 0 : dp[i - 1];
                dp[j] = max(dp[j] , curr_max * (j - i + 1) + prev);
            }
        }
        return dp[n - 1];
    }
};