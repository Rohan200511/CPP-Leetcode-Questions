class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = 0;
        for (int x : nums) mx = max(mx, x);

        vector<int> score(mx + 1, 0);
        for (int x : nums) score[x] += x;

        vector<int> dp(mx + 1, 0);
        dp[0] = 0;
        dp[1] = score[1];

        for (int i = 2; i <= mx; i++)
            dp[i] = max(dp[i - 1], score[i] + dp[i - 2]);

        return dp[mx];
    }
};