class Solution {
public:
    int dp[101][101];

    int solve(int i, int M, vector<int>& piles) {
        int n = piles.size();

        if (i >= n) return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;
        int sum = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            sum += piles[i + x - 1];

            int opp = solve(i + x, max(M, x), piles);

            int total = 0;
            for (int j = i; j < n; j++)
                total += piles[j];

            ans = max(ans, total - opp);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, piles);
    }
};