class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>pref(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                pref[i][j] = matrix[i][j];

                if(j > 0){
                    pref[i][j] += pref[i][j - 1];
                }
                if(i > 0){
                    pref[i][j] += pref[i-1][j];
                }
                if(i > 0 && j > 0){
                    pref[i][j] -= pref[i-1][j-1];
                }

            }
        }

        vector<vector<int>>ans(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int nr1 = (i - k) >= 0 ? (i - k) : 0;
                int nr2 = (i + k) < n ? (i + k) : n - 1;
                
                int nc1 = (j - k) >= 0 ? (j - k) : 0;
                int nc2 = (j + k) < m ? (j + k) : m - 1;

                ans[i][j] = pref[nr2][nc2];

                if(nr1 > 0) ans[i][j] -= pref[nr1-1][nc2];
                if(nc1 > 0) ans[i][j] -= pref[nr2][nc1-1];
                if(nr1 > 0 && nc1 > 0) ans[i][j] += pref[nr1-1][nc1-1];
            }
        }
        return ans;
    }
};