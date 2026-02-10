class Solution {
public:

    int mod = 1e9 +  7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>>minT(m , vector<long long>(n));
        vector<vector<long long>>maxT(m , vector<long long>(n));

        minT[0][0] = maxT[0][0] = grid[0][0];

        for(int i = 1 ; i < n ; i++){
            minT[0][i] = grid[0][i] * minT[0][i-1];
            maxT[0][i] = grid[0][i] * maxT[0][i-1];
        }
        
        for(int i = 1 ; i < m ; i++){
            minT[i][0] = grid[i][0] * minT[i-1][0];
            maxT[i][0] = grid[i][0] * maxT[i-1][0];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                long long  a = grid[i][j] * minT[i-1][j];
                long long b = grid[i][j] * minT[i][j-1];

                long long c = grid[i][j] * maxT[i-1][j];
                long long d = grid[i][j] * maxT[i][j-1];

                minT[i][j] = min<long long>({a , b , c , d});
                maxT[i][j] = max<long long>({a , b , c , d});
            }
        }
        return (int)(maxT[m-1][n-1] >= 0 ) ? (maxT[m-1][n-1]) % mod : -1;
    }
};