class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int target) {
        if (target == 0)
            return 1;

        if (target < 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        long long ways = 0;

        for (int x : nums)
            ways += solve(nums, target - x);

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target + 1, -1);
        return solve(nums, target);
    }
};