class Solution {
public:
    int n , m;
    vector<vector<int>>directions = {{0 , -1} , {0 , 1} , {1 , 0} , {-1 , 0}};

    bool dfs(int r , int c , vector<vector<int>>& grid , vector<vector<bool>>& vis){
        if(r == n-1) return true;
        vis[r][c] = true;

        for(auto& dir : directions){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(nr < n && nc < m && nr >= 0 && nc >= 0 && grid[nr][nc] == 0 && !vis[nr][nc]){
                if(dfs(nr , nc , grid , vis)) return true;
            }
        }
        return false;
    }

    bool canCross(int day , vector<vector<int>>& cells){
        vector<vector<int>>grid(n , vector<int>(m , 0));

        for(int i = 0 ; i < day ; i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<bool>>vis(n , vector<bool>(m , false));

        for(int j = 0 ; j < m ; j++){
            if(grid[0][j] == 0 && !vis[0][j]){
               if(dfs(0 , j , grid , vis)) return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row;
        m = col;

        int low = 1;
        int high = n*m;
        int ans = 0;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(canCross(mid , cells)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};