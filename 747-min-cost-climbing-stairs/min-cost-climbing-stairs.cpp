class Solution {
public:
    int n;
    
    vector<int>dp1 , dp2;

    int solve(vector<int>& cost , int i , vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take1 =  solve(cost , i + 1 , dp);
        int take2 =  solve(cost , i + 2 , dp);

        return dp[i] = cost[i] + min(take1 , take2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();

        dp1.assign(n + 2 , -1);
        dp2.assign(n + 2 , -1);

        return min(solve(cost , 0 , dp1) , solve(cost , 1 , dp2));  
    }
};