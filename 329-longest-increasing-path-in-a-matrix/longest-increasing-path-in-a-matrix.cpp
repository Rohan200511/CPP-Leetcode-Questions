class Solution {
public:
    int n , m;
    vector<vector<int>>directions = {{ 1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
    vector<vector<int>>vis;

    int dfs(vector<vector<int>>& matrix , int i , int j){

        if(vis[i][j] != -1) return vis[i][j];

        int len = 1;

        for(auto& dir : directions){
            int nr = i + dir[0];
            int nc = j + dir[1];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[i][j] < matrix[nr][nc])
                len = max(len , 1 + dfs(matrix , nr , nc));
        }
        return vis[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vis.assign(n , vector<int>(m , -1));
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans , dfs(matrix , i ,j));
            }
        }

        return ans;
    }
};