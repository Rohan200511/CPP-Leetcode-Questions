class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n + 1 , 0);

        for(int i = 1 ; i <= n ; i++){
            int curr_max = INT_MIN;

            for(int j = i ; j <= n && j - i + 1 <= k ; j++){
                curr_max = max(curr_max , arr[j-1]);
                dp[j] = max(dp[j] , curr_max * (j - i + 1) + dp[i-1]);
            }
        }
        return dp[n];
    }
};