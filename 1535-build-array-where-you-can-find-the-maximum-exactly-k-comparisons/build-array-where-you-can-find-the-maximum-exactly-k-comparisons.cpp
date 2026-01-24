class Solution {
public:
    
    int N , M , K;
    int dp[51][101][101];

    const int MOD = 1e9 + 7;
    int solve(int idx , int search_cost , int maxVal){
        if(idx == N){
            if(search_cost == K) return 1;
            return 0;
        }
        if(dp[idx][search_cost][maxVal] != -1) return dp[idx][search_cost][maxVal];
        long long result = 0;

        for(int num = 1 ; num <= M ; num++){

            if(num > maxVal){
                result += (solve(idx+1 , search_cost+1 , num));
            }

            else result += (solve(idx+1 , search_cost , maxVal));

            if (result >= MOD) result %= MOD;
        }
        return dp[idx][search_cost][maxVal] = (int)result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , 0);
    }
};