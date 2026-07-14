class Solution {
public:

    int n;
    int dp[201][201][201];
    int MOD = 1e9 + 7;

    int solve(int i , int s1 , int s2 , vector<int>& nums){
        if(i == n){
            if(s1 != 0 && s2 != 0 && s1 == s2) return dp[i][s1][s2] = 1;
            return dp[i][s1][s2] = 0;
        }

        if(dp[i][s1][s2] != -1) return dp[i][s1][s2];

        long long ignore = (solve(i + 1 , s1 , s2 , nums)) % MOD;

        int ns1 = (s1 == 0) ? nums[i] : gcd(s1 , nums[i]);
        long long take1 = (solve(i + 1 , ns1 , s2 , nums)) % MOD;

        int ns2 = (s2 == 0) ? nums[i] : gcd(s2 , nums[i]);
        long long take2 = (solve(i + 1 , s1 , ns2 , nums)) % MOD;

        return dp[i][s1][s2] = (ignore + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , 0 , nums);
    }
};