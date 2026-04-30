class Solution {
public:

    int k , n , m;
    vector<vector<vector<int>>>dp;

    int solve(vector<vector<int>>& grid , int i , int j , int cost){

        if(i >= n || j >= m) return -1;

        int cell = grid[i][j];
        int add_cost = (cell == 0) ? 0 : 1;
        int score = (cell == 0) ? 0 : (cell == 1 ? 1 : 2);

        int newcost = cost + add_cost;

        if(newcost > k) return -1;

        if(dp[i][j][newcost] != -2) return dp[i][j][newcost];

        if(i == n - 1 && j == m - 1) return score;

        int right = solve(grid , i , j + 1 , newcost);
        int down = solve(grid , i + 1 , j , newcost);

        int best = max(right, down);

        if (best == -1) return dp[i][j][newcost] = -1;

        return dp[i][j][newcost] = best + score;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        this->k = k;
        n = grid.size();
        m = grid[0].size();

        dp.assign(n , vector<vector<int>>(m , vector<int>(1001 , -2)));

        int ans = solve(grid , 0 , 0 , 0);

        return ans;
    }
};