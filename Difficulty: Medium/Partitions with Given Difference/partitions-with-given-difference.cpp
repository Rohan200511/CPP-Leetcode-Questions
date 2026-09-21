class Solution {
  public:
    
    int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        
        if (i == arr.size()) {
            return target == 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = solve(i + 1, target, arr, dp);

        int take = 0;
        if (arr[i] <= target)
            take = solve(i + 1, target - arr[i], arr, dp);

        return dp[i][target] = take + notTake;
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = accumulate(arr.begin(), arr.end(), 0);

            if (total + diff < 0 || (total + diff) % 2 != 0)
                return 0;

            int target = (total + diff) / 2;

            vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

            return solve(0, target, arr, dp);
    }
};