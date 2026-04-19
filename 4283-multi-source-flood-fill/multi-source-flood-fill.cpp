class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n, vector<int>(m , 0));
        vector<vector<int>>time(n, vector<int>(m , INT_MAX));

        queue<tuple<int,int,int,int>>q;

        for(auto& it : sources){
            int row = it[0];
            int col = it[1];
            int c   = it[2];
            
            grid[row][col] = c;
            time[row][col] = 0;
            q.push({row , col , c , 0});
        }

        vector<vector<int>>dirs = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

        while(!q.empty()){
            auto [row , col , val , t] = q.front();
            q.pop();

            for(auto& dir : dirs){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if(nr < n && nr >= 0 && nc < m && nc >= 0){
                    if(time[nr][nc] > (t + 1) && grid[nr][nc] < val){
                        grid[nr][nc] = val;
                        time[nr][nc] = t + 1;
                        q.push({nr , nc , val , t+1});
                    }

                    else if(time[nr][nc] == (t + 1) && grid[nr][nc] < val){
                        grid[nr][nc] = max(val , grid[nr][nc]);
                        time[nr][nc] = t + 1;
                        q.push({nr , nc , grid[nr][nc] , t+1});
                    }
                }
            }
        }
        return grid;
    }
};