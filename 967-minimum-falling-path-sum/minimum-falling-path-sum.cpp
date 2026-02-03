class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int dfs(int r, int c, const vector<vector<int>>& matrix) {
        if (c < 0 || c >= n) return INT_MAX;
        if (r == n - 1) return matrix[r][c];

        if (memo[r][c] != INT_MAX)
            return memo[r][c];

        int downLeft  = dfs(r + 1, c - 1, matrix);
        int down      = dfs(r + 1, c, matrix);
        int downRight = dfs(r + 1, c + 1, matrix);

        int bestNext = min({downLeft, down, downRight});
        if (bestNext == INT_MAX) return memo[r][c] = INT_MAX;

        return memo[r][c] = matrix[r][c] + bestNext;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memo.assign(n, vector<int>(n, INT_MAX));
        
        int best = INT_MAX;

        for (int col = 0; col < n; col++) {
            best = min(best, dfs(0, col, matrix));
        }

        return best;
    }
};
