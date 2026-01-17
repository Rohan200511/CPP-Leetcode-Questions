class Solution {
public: 
    vector<vector<int>>t;

    int dfs(int m , int n , int i , int j){

        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;

        if(t[i][j] != -1) return t[i][j];

        int down =  dfs(m , n , i+1 , j);
        int right =  dfs(m , n , i , j+1);

        return t[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        t.assign(m , vector<int>(n , -1));
        return dfs(m , n , 0 , 0);
    }
};