class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        vector<vector<int>>t(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){
                    t[i][j] = (matrix[i][j] == 0) ? 0 : 1;
                    ans += t[i][j];
                }

                else{
                    if(matrix[i][j] == 0) t[i][j] = 0;
                    else{
                        int top = t[i-1][j];
                        int left = t[i][j-1];
                        int diagonal = t[i-1][j-1];

                        t[i][j] = 1 + min({top , left , diagonal});
                        ans += t[i][j];
                    }
                }
            }
        }
        return ans;
    }
};