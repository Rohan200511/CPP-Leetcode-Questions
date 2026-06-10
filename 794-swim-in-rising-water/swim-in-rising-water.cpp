class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({grid[0][0],0,0});

        vector<vector<bool>>vis(n , vector<bool>(m ,false));

        vector<vector<int>>dirs = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};


        while(!pq.empty()){
            auto [time , row , col] = pq.top();
            pq.pop();

            if(row == n-1 && col == m-1) return time;
            
            if(vis[row][col]) continue;
            vis[row][col] = true;

            for(auto& dir : dirs){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]){
                    int new_time = max(time , grid[nr][nc]);
                    pq.push({new_time , nr , nc});
                }
            }
        }
        return -1;
    }
};